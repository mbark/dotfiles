;;;; lang/typescript/config.el -*- lexical-binding: t; -*-

(def-package! prettier-js)

(def-package! typescript-mode
  :mode "\\.ts$"
  :config
  (add-hook 'typescript-mode-hook #'rainbow-delimiters-mode)
  (add-hook 'typescript-mode-hook #'prettier-js-mode)
  (set! :electric 'typescript-mode :chars '(?\} ?\)) :words '("||" "&&")))

(def-package! tide
  :hook (typescript-mode . tide-setup)
  :init
  (defun +typescript|init-tide-in-web-mode ()
    (when (string= (file-name-extension (or buffer-file-name "")) "tsx")
      (tide-setup)))
  (add-hook 'web-mode-hook #'+typescript|init-tide-in-web-mode)
  :config
  (set! :company-backend 'typescript-mode '(company-tide))
  (set! :lookup 'typescript-mode
    :definition #'tide-jump-to-definition
    :references #'tide-references
    :documentation #'tide-documentation-at-point)

  (setq tide-format-options
        '(:insertSpaceAfterFunctionKeywordForAnonymousFunctions t
          :placeOpenBraceOnNewLineForFunctions nil))

  (def-menu! +typescript/refactor-menu
    "Refactor commands for `typescript-mode` buffers."
    '(("rename symbol"              :exec tide-rename-symbol)
      ("refactor"                   :exec tide-refactor)
      ("fix"                        :exec tide-fix)
      ("jsdoc"                      :exec tide-jsdoc-template)
      ("format"                     :exec tide-format)
      ("organize imports"           :exec tide-organize-imports)
      ("restart tide server"        :exec tide-restart-server)))

  (map! :map tide-mode-map
        :localleader
        :n "=" #'tide-format
        :n "R" #'tide-restart-server
        :n "t" #'tide-jsdoc-template
        (:prefix "r"
          :n "." #'+typescript/refactor-menu
          :n "r" #'tide-refactor
          :n "f" #'tide-fix
          :n "o" #'tide-organize-imports
          :n "s" #'tide-rename-symbol))

  (add-hook! 'tide-mode-hook #'(flycheck-mode eldoc-mode)))

(def-project-mode! +typescript-npm-mode
  :modes (typescript-mode)
  :files "package.json"
  :on-enter
  (when (make-local-variable 'exec-path)
    (push (doom-project-expand "node_modules/.bin")
          exec-path)))

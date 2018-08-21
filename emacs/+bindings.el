;;; +bindings.el -*- lexical-binding: t; -*-

(map!
 ;; --- <tide> ----------------------------------------
  (:after tide
   (:map tide-mode-map
     :localleader
     :n "f" #'tide-fix
     :n "R" #'tide-rename-symbol))

  ;; --- <leader> -------------------------------------
  (:leader
    (:desc "error" :prefix "e"
           :desc "Next error"           :nv "n" #'flycheck-next-error
           :desc "Previous error"       :nv "p" #'flycheck-previous-error)

    (:desc "search" :prefix "/"
           :desc "Resume last"          :n "r" #'helm-resume)

    (:desc "project" :prefix "p"
           :desc "Find file in project"    :n "f" #'projectile-find-file
           :desc "Search project"          :n "s" #'helm-projectile-rg)

    (:desc "jump" :prefix "j"
           :desc "To word"               :n "w" #'avy-goto-word-1
           :desc "To line"               :n "l" #'avy-goto-line
           :desc "To char"               :n "j" #'avy-goto-char-2))

  ;; -- Smartparens -----------------------------------
  :i "C->" #'sp-forward-slurp-sexp
  :n "C->" #'sp-forward-slurp-sexp
  :i "C-<" #'sp-backward-barf-sexp
  :n "C-<" #'sp-backward-barf-sexp)


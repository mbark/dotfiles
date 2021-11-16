;;; config.el -*- lexical-binding: t; -*-


(load! "+bindings")

(after! evil-escape
  (setq evil-escape-key-sequence "kj"))

;; Use challenger-deep theme
(setq doom-theme 'doom-challenger-deep)

(setq doom-font (font-spec :family "Fira Code" :size 12)
      doom-variable-pitch-font (font-spec :family "Fira Code")
      doom-unicode-font (font-spec :family "Fira Code")
      doom-big-font (font-spec :family "Fira Code" :size 19))

;; Protobuf mode
(use-package! protobuf-mode
  :mode "\\.proto\\'")

(use-package! graphql-mode
  :mode "\\.gql\\'")

(after! company
  (setq company-idle-delay 0.15))

(after! lsp-mode
  (lsp-register-custom-settings
   '(("gopls.experimentalWorkspaceModule" t t))))

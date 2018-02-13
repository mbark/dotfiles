;;; private/mbark/config.el -*- lexical-binding: t; -*-

(load! +bindings)

;;
;; Plugins
;;

(def-package! dracula-theme)

;;
;; Config
;;

(after! evil-escape
  (setq evil-escape-key-sequence "kj"))

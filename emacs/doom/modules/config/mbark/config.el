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

;; fix to make chunkwm tile properly
(setq frame-resize-pixelwise t)

;; transparent background
(set-frame-parameter (selected-frame) 'alpha '(85 . 50))

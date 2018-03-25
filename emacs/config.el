;;; config.el -*- lexical-binding: t; -*-

(load! +bindings)

;;
;; Plugins
;;

;;
;; Config
;;

(after! evil-escape
  (setq evil-escape-key-sequence "kj"))

;; fix to make chunkwm tile properly
(setq frame-resize-pixelwise t)

;; transparent background
(set-frame-parameter (selected-frame) 'alpha '(100 . 50))

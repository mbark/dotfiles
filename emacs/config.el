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

(after! company
  (setq company-idle-delay 0.1
        company-minimum-prefix-length 2))

;; fix to make chunkwm tile properly
(setq frame-resize-pixelwise t)

;; transparent background
(set-frame-parameter (selected-frame) 'alpha '(85 . 50))

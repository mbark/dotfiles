;;; config.el -*- lexical-binding: t; -*-

(load! "+bindings")

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
(set-frame-parameter (selected-frame) 'alpha '(85 . 50))

;; Prefer dracula over other themes
(setq doom-theme 'doom-challenger-deep)

(setq doom-font (font-spec :family "Fira Code" :size 12)
      doom-variable-pitch-font (font-spec :family "Fira Code")
      doom-unicode-font (font-spec :family "Fira Code")
      doom-big-font (font-spec :family "Fira Code" :size 19))

;; redefine avy but with another command appended (goto-word)
(def-package! avy
  :commands (avy-goto-char-2 avy-goto-word-1))

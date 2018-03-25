;;; init.el -*- lexical-binding: t; -*-

(doom!
  :lang
  typescript
  go)

;; Prefer dracula over other themes
(setq doom-theme 'doom-dracula)

(setq doom-font (font-spec :family "Fira Code" :size 12)
      doom-variable-pitch-font (font-spec :family "Fira Code")
      doom-unicode-font (font-spec :family "Fira Code")
      doom-big-font (font-spec :family "Fira Code" :size 19))

;; redefine avy but with another command appended (goto-word)
(def-package! avy
  :commands (avy-goto-char-2 avy-goto-line avy-goto-word-1))

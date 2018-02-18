;;; private/mbark/+bindings.el -*- lexical-binding: t; -*-

(map!
 ;; --- <leader> -------------------------------------
 (:leader
   (:desc "previous..." :prefix "["
     :desc "Flycheck error"       :nv "!" #'flycheck-previous-error)

   (:desc "next..." :prefix "]"
     :desc "Flycheck error"       :nv "!" #'flycheck-next-error)

   (:desc "search" :prefix "/"
     :desc "Resume last"          :n "r" #'ivy-resume)

   (:desc "project" :prefix "p"
     :desc "Switch project"          :n "p" #'counsel-projectile-switch-project
     :desc "Find file in project"    :n "f" #'projectile-find-file
     :desc "Search project"          :n "s" #'counsel-projectile-rg)

   (:desc "jump" :prefix "j"
     :desc "To word"               :n "w" #'avy-goto-word-1
     :desc "To line"               :n "l" #'avy-goto-line
     :desc "To char"               :n "j" #'avy-goto-char-2))

 ;; -- Smartparens -----------------------------------
 :i "C->" #'sp-forward-slurp-sexp
 :n "C->" #'sp-forward-slurp-sexp
 :i "C-<" #'sp-backward-barf-sexp
 :n "C-<" #'sp-backward-barf-sexp

 ;; --- Major mode bindings --------------------------
 (:after markdown-mode
   (:map markdown-mode-map
     ;; fix conflicts with private bindings
     "<backspace>" nil
     "<M-left>"    nil
     "<M-right>"   nil)))

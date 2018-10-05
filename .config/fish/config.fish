function private_key_bindings
    fish_vi_key_bindings
    bind -M insert -m default kj force-repaint
    bind -M insert \ck up-or-search
    bind -M insert \cj down-or-search
    fish_default_key_bindings -M insert
end

set -g fish_key_bindings private_key_bindings

# exa <3
alias ll="exa -laFh --git"

# why use vim when you can use neovim?
alias vim="nvim"

# convenience to keep one tmux session running
alias tmux-reattach="tmux new-session -s work -A"

# dotfile management
alias dots="/usr/bin/git --git-dir=$HOME/dotfiles/.git --work-tree=$HOME"
complete --command dots --wraps bar

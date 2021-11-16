function private_key_bindings
    fish_vi_key_bindings
    bind -M insert -m default kj force-repaint
    bind -M insert \ck up-or-search
    bind -M insert \cj down-or-search
    fish_default_key_bindings -M insert
end

set -g fish_key_bindings private_key_bindings

# fisher
if not functions -q fisher
    set -q XDG_CONFIG_HOME; or set XDG_CONFIG_HOME ~/.config
    curl https://git.io/fisher --create-dirs -sLo $XDG_CONFIG_HOME/fish/functions/fisher.fish
    fish -c fisher
end

# exa <3
alias ll="exa -laFh --git"

# why use vim when you can use neovim?
alias vim="nvim"

# convenience to keep one tmux session running
alias tmux-reattach="tmux new-session -s work -A"

function gup
    set root (git rev-parse --show-toplevel)
    if [ -n "$root" ];
        cd "$root"
    else
       echo "not in a git repo" 1>&2
    end
end

# dotfile management
alias dots="/usr/bin/git --git-dir=$HOME/dotfiles --work-tree=$HOME"
complete --command dots --wraps git
set -g fish_user_paths "$HOME/go/bin" $fish_user_paths
eval (direnv hook fish)
source /usr/local/opt/asdf/asdf.fish
fish_add_path /usr/local/sbin

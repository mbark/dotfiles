set -g fish_key_bindings private_key_bindings

# fisher
if not functions -q fisher
    set -q XDG_CONFIG_HOME; or set XDG_CONFIG_HOME ~/.config
    curl https://git.io/fisher --create-dirs -sLo $XDG_CONFIG_HOME/fish/functions/fisher.fish
    fish -c fisher
end

# eza <3
alias ll="eza -lah --git"

# why use vim when you can use neovim?
alias vim="nvim"

# convenience to keep one tmux session running
alias tmux-reattach="tmux new-session -s work -A"

function gup
    set root (git rev-parse --show-toplevel)
    if [ -n "$root" ]

        cd "$root"
    else
        echo "not in a git repo" 1>&2
    end
end

function kubeconf
    set -l KC $HOME/.kube/config
    rm -f $KC

    set -l rack $argv[1]
    convox rack kubeconfig -r $rack | sed "s/rack/$rack/" | grep -v current-context >$HOME/.kube/$rack

    yq e -i ".contexts[0].context.user = \"$rack\"" $HOME/.kube/$rack
    yq e -i ".users[0].name = \"$rack\"" $HOME/.kube/$rack

    set -l kube_files (find $HOME/.kube -type f -maxdepth 1 | tr '\n' ':' | sed 's/:$//')
    set -x KUBECONFIG "$KC:$kube_files"

    kubectl config view --flatten >$KC

    set -x KUBECONFIG $KC
    kubectl config use-context convox@$rack
end

# dotfile management
alias dots="/usr/bin/git --git-dir=$HOME/dotfiles --work-tree=$HOME"
alias mdslack="pbpaste | ruby ~/.config/private/md_slack.rb | pbcopy"

complete --command dots --wraps git
set -g fish_user_paths "$HOME/go/bin" $fish_user_paths
set -x EDITOR nvim
set -gx PATH $HOMEBREW_PREFIX/opt/coreutils/libexec/gnubin $PATH

if type -q direnv
    eval (direnv hook fish)
end

eval (/opt/homebrew/bin/brew shellenv fish)
mise activate fish | source
fish_add_path /usr/local/sbin
fish_add_path "$HOME/.arkade/bin"

if test "$TERM_PROGRAM" != WarpTerminal
    function private_key_bindings
        fish_vi_key_bindings
        bind -M insert -m default kj force-repaint
        bind -M insert \ck up-or-search
        bind -M insert \cj down-or-search
        fish_default_key_bindings -M insert
    end
end

function killport
    if test (count $argv) -ne 1
        echo "Usage: killport <port>"
        return 1
    end

    set port $argv[1]
    set pid (lsof -ti :$port)

    if test -z "$pid"
        echo "No process is using port $port"
        return 1
    end

    echo "Killing process $pid using port $port..."
    kill -9 $pid
end
export PATH="$HOME/.local/bin:$PATH"

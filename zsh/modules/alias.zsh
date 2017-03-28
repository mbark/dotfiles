#!/bin/zsh

# Define this first so that other scripts can use it
confirm() {
    # call with a prompt string or use a default
    read -r "?${1:-Are you sure? [y/N]} " response
    case $response in
        [yY][eE][sS]|[yY])
            true
            ;;
        *)
            false
            ;;
    esac
}

alias ls="k --almost-all --human --no-vcs"
alias ll="k --almost-all --human"

alias tmux-reattach="tmux new-session -s work -A"

# Use the brew installed one to allow usage of the -R flag
alias ctags="`brew --prefix`/bin/ctags"

function git-delete-branches {
    git branch --merged | egrep -v "(^\*|master)" | xargs -r git branch -d
}

function update-zplug() {
    source "$HOME/dotfiles/zsh/zplug.zsh"

    if ! zplug check --verbose; then
        printf "Install? [y/N]: "
        if read -q; then
            echo; zplug install
        fi
        zplug load
    fi

    zplug update
}

function update-all() {
    echo "Updating submodules in dotfiles"
    (cd ~/dotfiles && git submodule update --recursive --remote)

    echo "Updating brew formulas"
    brew update && brew upgrade

    echo "Updating zplug"
    update-zplug

    echo "Updating global npm packages"
    npm update -g

    # Remember:
    # if we update ycmd we need to rebuild it
    # python3 build.py --clang-completer --racer-completer --tern-completer
    # and update emacs-ycmd:
    # if we update imagmagick sometimes we might need to rebuild emacs as well
    # brew uninstall emacs-plus && brew install emacs-plus
}

function ycmd-generate() {
    local dir=$(pwd)
    set -x
    (cd ~/dotfiles/dependencies/YCM-generator &&
         env OPENSSL_ROOT_DIR=/usr/local/opt/openssl/ \
             python config_gen.py --verbose --preserve-environment "$dir" $@)
}

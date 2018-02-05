#!/bin/zsh

alias ls="k --almost-all --human --no-vcs"
alias ll="k --almost-all --human"

alias tmux-reattach="tmux new-session -s work -A"

# Use the brew installed one to allow usage of the -R flag
alias ctags="/usr/local/bin/ctags"

function update-all() {
    echo "Updating submodules in dotfiles"
    (cd ~/dotfiles && git submodule update --init --recursive)

    echo "Updating brew formulas"
    brew update && brew upgrade

    echo "Updating zplugin"
    zplugin self-update
    zplugin update --all

    echo "Updating global javascript packages"
    yarn global upgrade

    # Remember:
    # if we update ycmd we need to rebuild it:
    # python3 build.py --clang-completer --racer-completer --tern-completer
    # and update emacs-ycmd
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


# Send a signal to emacs to make it stop whatever it is doing if it hangs up.
#
# The default signal is SIGUSR2 which will make emacs stop what it is doing
# and enter debug mode. If this was just some fluke, remember to
# M-x toggle-debug-on-quit
function emacs-ping() {
    local sig=SIGUSR2
    if [ -n "$1" ]; then
        sig="$1"
    fi

    ps aux | grep -ie Emacs | grep -v grep | awk '{print $2}' | xargs kill -"$1"
}

function kill-port() {
    local port="$1"
    if [ -z "$1" ]; then
        echo '\e[0;31m ERROR:\033[0m' "$1"
    fi

    netstat -vanp tcp | grep \\."$1" | grep LISTEN | awk '{print $9}' | xargs kill -9
}

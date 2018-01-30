#!/bin/zsh

# Reset
Color_Off='\033[0m'       # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bold
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White

# Underline
UBlack='\033[4;30m'       # Black
URed='\033[4;31m'         # Red
UGreen='\033[4;32m'       # Green
UYellow='\033[4;33m'      # Yellow
UBlue='\033[4;34m'        # Blue
UPurple='\033[4;35m'      # Purple
UCyan='\033[4;36m'        # Cyan
UWhite='\033[4;37m'       # White

# Background
On_Black='\033[40m'       # Black
On_Red='\033[41m'         # Red
On_Green='\033[42m'       # Green
On_Yellow='\033[43m'      # Yellow
On_Blue='\033[44m'        # Blue
On_Purple='\033[45m'      # Purple
On_Cyan='\033[46m'        # Cyan
On_White='\033[47m'       # White

# High Intensity
IBlack='\033[0;90m'       # Black
IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
IBlue='\033[0;94m'        # Blue
IPurple='\033[0;95m'      # Purple
ICyan='\033[0;96m'        # Cyan
IWhite='\033[0;97m'       # White

# Bold High Intensity
BIBlack='\033[1;90m'      # Black
BIRed='\033[1;91m'        # Red
BIGreen='\033[1;92m'      # Green
BIYellow='\033[1;93m'     # Yellow
BIBlue='\033[1;94m'       # Blue
BIPurple='\033[1;95m'     # Purple
BICyan='\033[1;96m'       # Cyan
BIWhite='\033[1;97m'      # White

# High Intensity backgrounds
On_IBlack='\033[0;100m'   # Black
On_IRed='\033[0;101m'     # Red
On_IGreen='\033[0;102m'   # Green
On_IYellow='\033[0;103m'  # Yellow
On_IBlue='\033[0;104m'    # Blue
On_IPurple='\033[0;105m'  # Purple
On_ICyan='\033[0;106m'    # Cyan
On_IWhite='\033[0;107m'   # White


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

export ZGEN_RESET_ON_CHANGE=(${HOME}/dotfiles/zshrc)

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

alias vim="nvim"
alias vi="nvim"
export EDITOR="vim"
export USE_EDITOR=$EDITOR
export VISUAL=$EDITOR

# use ctrl p and n to step through the history
bindkey "^P" up-line-or-search
bindkey "^N" down-line-or-search

# Use vi-mode
bindkey -v
export KEYTIMEOUT=20

bindkey -M viins 'kj' vi-cmd-mode

# Configuration for fzf
export FZF_DEFAULT_COMMAND='rg --files --no-ignore --hidden --follow --glob "!.git/*"'
export FZF_CTRL_T_COMMAND="$FZF_DEFAULT_COMMAND"

# fzf auto-completion
[[ $- == *i* ]] && source "/usr/local/opt/fzf/shell/completion.zsh" 2> /dev/null

# get the keybindings for fzf
source "/usr/local/opt/fzf/shell/key-bindings.zsh"

# auto completion for sshrc
compdef sshrc=ssh

# initalize fasd
eval "$(fasd --init auto)"

# Allows using gitignore io via the command line
function gi() {
    if [ "$1" = "list" ] || [ -z "$1" ] ; then
        curl -sL https://www.gitignore.io/api/list | tr "," "\n"
    else
        curl -sL https://www.gitignore.io/api/${(j:,:)@}
    fi
}

alias docker-cleanup="/bin/bash ~/dotfiles/scripts/docker-cleanup.sh"
alias case-sensitive-fs="/bin/bash ~/dotfiles/scripts/case-sensitive-fs.sh"
alias ls="ls -lah --color"

# Use the brew installed one to allow usage of the -R flag
alias ctags="`brew --prefix`/bin/ctags"

alias tmux-reattach="tmux new-session -s prezto -A"

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

function docker-cleanall() {
    if confirm ; then
        docker rm $(docker ps -a -q)
        docker rmi $(docker images -q)
    fi
}

function lg() {
    /bin/ls -lah | grep $1
}

# use fzf to find lastpass password
function pass() {
    lpass show -c --password $(lpass ls  | fzf | awk '{print $(NF)}' | sed 's/\]//g')
}

function update-all() {
    set -x
    (cd ~/dotfiles && git submodule update --recursive --remote)
    brew update && brew upgrade
    zgen update
    npm update -g
    set +x
}

function ycmd-generate() {
    local dir=$(pwd)
    (cd ~/dotfiles/YCM-generator &&
         env OPENSSL_ROOT_DIR=/usr/local/opt/openssl/ \
             python config_gen.py --verbose --preserve-environment "$dir" "$@")
}

z() {
    local dir
    dir="$(fasd -Rdl "$1" | fzf -1 -0 --no-sort +m)" && cd "${dir}" || return 1
}

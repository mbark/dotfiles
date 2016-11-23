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

alias tmux-reattach="tmux new-session -s prezto -A"

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

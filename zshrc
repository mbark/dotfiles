export ZGEN_RESET_ON_CHANGE=(${HOME}/dotfiles/zshrc)

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

alias vim="nvim"
alias vi="nvim"
export EDITOR="vim"
export USE_EDITOR=$EDITOR
export VISUAL=$EDITOR

alias docker-cleanup="/bin/bash ~/dotfiles/scripts/docker-cleanup.sh"
alias ls="ls -lah --color"

# use ctrl p and n to step through the history
bindkey "^P" up-line-or-search
bindkey "^N" down-line-or-search

# Use vi-mode
bindkey -v
export KEYTIMEOUT=20

bindkey -M viins 'kj' vi-cmd-mode

# Configuration for fzf
export FZF_DEFAULT_COMMAND='ag -g ""'
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

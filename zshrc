# load zgen
source "${HOME}/.zgen/zgen.zsh"

# if the init scipt doesn't exist
if ! zgen saved ; then
    zgen prezto editor key-bindings 'vi'
    zgen prezto editor dot-expansion 'yes'
    zgen prezto prompt theme 'steeef'
    zgen prezto tmux:auto-start local 'yes'
    zgen prezto tmux:auto-start remote 'yes'

    zgen prezto

    zgen prezto archive
    zgen prezto completion
    zgen prezto directory
    zgen prezto git
    zgen prezto gnu-utility
    zgen prezto history
    zgen prezto homebrew
    zgen prezto osx
    zgen prezto tmux
    zgen prezto utility

    # must be loaded after the completion module
    zgen prezto fasd

    # these should be loaded 2nd last and last respectively
    zgen prezto syntax-highlighting
    zgen prezto prompt

    # zgen load b4b4r07/enhancd init
    zgen load chrissicool/zsh-256color
    zgen load djui/alias-tips
    zgen load jreese/zsh-titles
    zgen load supercrabtree/k
    zgen load unixorn/autoupdate-zgen
    zgen load unixorn/tumult.plugin.zsh
    zgen load zlsun/solarized-man

    # must be loaded at the end of the file
    zgen load zsh-users/zsh-syntax-highlighting

    zgen save
fi

export ZGEN_RESET_ON_CHANGE=(${HOME}/dotfiles/zshrc)

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

export EDITOR="vim"
export USE_EDITOR=$EDITOR
export VISUAL=$EDITOR

export ENHANCD_FILTER=fzf

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

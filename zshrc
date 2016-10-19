# load zgen
source "${HOME}/dotfiles/zsh/zgen/zgen.zsh"

# don't show the <<< even though we got the vi-mode plugin
export RPS1="%{$reset_color%}"

# if the init scipt doesn't exist
if ! zgen saved; then
    zgen oh-my-zsh

    zgen oh-my-zsh plugins/brew
    zgen oh-my-zsh plugins/command-not-found
    zgen oh-my-zsh plugins/docker
    zgen oh-my-zsh plugins/git
    zgen oh-my-zsh plugins/gnu-utils
    zgen oh-my-zsh plugins/osx
    zgen oh-my-zsh plugins/sudo
    zgen oh-my-zsh plugins/vi-mode

    zgen load b4b4r07/enhancd
    zgen load chrissicool/zsh-256color
    zgen load djui/alias-tips
    zgen load jreese/zsh-titles
    zgen load supercrabtree/k
    zgen load unixorn/autoupdate-zgen
    zgen load unixorn/tumult.plugin.zsh
    zgen load willghatch/zsh-saneopt
    zgen load zlsun/solarized-man
    zgen load zsh-users/zsh-completions

    # the theme used
    zgen load denysdovhan/spaceship-zsh-theme spaceship

    # must be loaded at the end of the file
    zgen load zsh-users/zsh-syntax-highlighting

    zgen save
fi

ZGEN_RESET_ON_CHANGE=(${HOME}/.zshrc)

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

export EDITOR="vim"
export USE_EDITOR=$EDITOR
export VISUAL=$EDITOR

export ENHANCD_FILTER=fzf

export ZSH=$HOME/.oh-my-zsh
export ZSH_CUSTOM=$HOME/.zsh
export ZSH_THEME="spaceship"

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

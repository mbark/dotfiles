# This must be set before loading zplug
PURE_PROMPT_SYMBOL='$(nice_exit_code)❯'

source "$ZPLUG_HOME/init.zsh"
source "$HOME/dotfiles/zsh/zplug.zsh"

# Editor settings
alias vim="nvim"
alias vi="nvim"
export EDITOR="vim"
export USE_EDITOR=$EDITOR
export VISUAL=$EDITOR

# Use vi-mode
bindkey -v
export KEYTIMEOUT=20
bindkey -M viins 'kj' vi-cmd-mode

# Bind some nice have shortcuts
bindkey "^K" up-line-or-search
bindkey "^J" down-line-or-search
bindkey '^W' vi-backward-kill-word

# Allow commands to be commented out
setopt interactivecomments

# Initialization of thefuck
eval "$(thefuck --alias)"

# Fuzzy config variables
export SKIM_DEFAULT_COMMAND='rg --files --no-ignore --hidden --follow --glob "!.git/*"'
export FZF_DEFAULT_COMMAND='rg --files --no-ignore --hidden --follow --glob "!.git/*"'
source "/usr/local/opt/fzf/shell/key-bindings.zsh"

# auto completion for sshrc
compdef sshrc=ssh

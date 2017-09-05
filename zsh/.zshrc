export NVM_LAZY_LOAD=true

source "$ZPLUG_HOME/init.zsh"
source "$HOME/dotfiles/zsh/zplug.zsh"

zplug load

# Editor settings
alias vim="nvim"
alias vi="nvim"
export EDITOR="emacsclient -c -a ''"
export USE_EDITOR="$EDITOR"
export GIT_EDITOR="$EDITOR"
export VISUAL="$EDITOR"

# Use vi-mode
bindkey -v
export KEYTIMEOUT=20
bindkey -M viins 'kj' vi-cmd-mode

# Bind some nice have shortcuts
bindkey "^K" up-line-or-search
bindkey "^J" down-line-or-search
bindkey '^W' vi-backward-kill-word

# And some emacs bindings as well
bindkey "^[f" forward-word
bindkey "^[b" backward-word
bindkey "^[w" backward-kill-word

# Insert autosuggestion
bindkey '^O' autosuggest-accept

# Fuzzy config variables
export SKIM_DEFAULT_COMMAND='rg --files --no-ignore --hidden --follow --glob "!.git/*"'
export FZF_DEFAULT_COMMAND='rg --files --no-ignore --hidden --follow --glob "!.git/*"'

# autocompletion for sshrc
compdef sshrc=ssh

# autocompletion for yarnhack (used with lerna)
compdef yarnhack=yarn

if [[ $(uname) == "Darwin" ]] ; then
    source "$FZF_PATH/shell/key-bindings.zsh"
else
    source "$FZF_PATH/key-bindings.zsh"
fi

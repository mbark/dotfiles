export NVM_LAZY_LOAD=true

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
bindkey "^F"  forward-char
bindkey "^B"  backward-char

# Insert autosuggestion
bindkey '^O' autosuggest-accept

# Fuzzy config variables
export SKIM_DEFAULT_COMMAND='rg --files --no-ignore --hidden --follow --glob "!.git/*"'
export FZF_DEFAULT_COMMAND='rg --files --no-ignore --hidden --follow --glob "!.git/*"'

### Added by Zplugin's installer
source "$HOME/.zplugin/bin/zplugin.zsh"
autoload -Uz _zplugin
(( ${+_comps} )) && _comps[zplugin]=_zplugin
### End of Zplugin's installer chunk

source "$HOME/dotfiles/zsh/zplugin.zsh"

autoload -Uz compinit
if [ $(date +'%j') != $(stat -f '%Sm' -t '%j' "$HOME/.zcompdump") ]; then
    compinit -d "$HOME/.zcompdump"
else
    compinit -C
fi


if [[ $(uname) == "Darwin" ]] ; then
    source "$FZF_PATH/shell/key-bindings.zsh"
else
    source "$FZF_PATH/key-bindings.zsh"
fi

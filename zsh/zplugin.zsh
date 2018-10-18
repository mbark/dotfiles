zplugin light mafredri/zsh-async

zplugin snippet OMZ::plugins/vi-mode/vi-mode.plugin.zsh

zplugin light zsh-users/zsh-completions

zplugin ice as"completion"; zplugin snippet https://github.com/docker/cli/blob/master/contrib/completion/zsh/_docker


zplugin light chrissicool/zsh-256color
zplugin light djui/alias-tips
zplugin light zlsun/solarized-man
zplugin light voronkovich/gitignore.plugin.zsh

zplugin light hlissner/zsh-autopair
zplugin light b4b4r07/zsh-vimode-visual

zplugin light sindresorhus/pure

zplugin snippet "$HOME/dotfiles/zsh/modules/alias.zsh"
zplugin snippet "$HOME/dotfiles/zsh/modules/completions.zsh"
zplugin snippet "$HOME/dotfiles/zsh/modules/fuzzy.zsh"
zplugin snippet "$HOME/dotfiles/zsh/modules/history.zsh"

zplugin ice wait'1' atload'_zsh_nvm_lazy_load'
zplugin light lukechilds/zsh-nvm

zplugin ice wait'1' atload'_zsh_autosuggest_start'
zplugin light zsh-users/zsh-autosuggestions
zplugin light zdharma/fast-syntax-highlighting

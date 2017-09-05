zplug "b4b4r07/zplug"

zplug "plugins/vi-mode", from:oh-my-zsh
zplug "plugins/kubectl", from:oh-my-zsh, lazy:true

zplug "zsh-users/zsh-completions"
zplug "docker/docker", use:"contrib/completion/zsh"
zplug "docker/compose", use:"contrib/completion/zsh"

zplug "supercrabtree/k"
zplug "lukechilds/zsh-nvm"

zplug "chrissicool/zsh-256color"
zplug "djui/alias-tips"
zplug "zlsun/solarized-man"
zplug "voronkovich/gitignore.plugin.zsh"
zplug "hlissner/zsh-autopair", defer:2

zplug "zdharma/fast-syntax-highlighting", defer:2
zplug "b4b4r07/zsh-vimode-visual", defer:3
zplug "zsh-users/zsh-autosuggestions", defer:3

zplug "mafredri/zsh-async", defer:0
zplug "sindresorhus/pure", use:"pure.zsh", as:theme

zplug "$HOME/dotfiles/zsh/modules", from:local, \
      use:"{alias,docker,fuzzy,history}.zsh"
zplug "$HOME/dotfiles/zsh/modules", from:local, \
      use:"completions.zsh", defer:2

zplug "b4b4r07/zplug"

zplug "plugins/git", from:oh-my-zsh
zplug "plugins/vi-mode", from:oh-my-zsh
zplug "plugins/emoji", from:oh-my-zsh
zplug "plugins/gnu-utils", from:oh-my-zsh

zplug "zsh-users/zsh-completions"
zplug "docker/docker", use:"contrib/completion/zsh"

zplug "supercrabtree/k"

zplug "chrissicool/zsh-256color"
zplug "djui/alias-tips"
zplug "zlsun/solarized-man"
zplug "voronkovich/gitignore.plugin.zsh"
zplug "bric3/nice-exit-code"
zplug "Vifon/deer", use:deer

zplug "zsh-users/zsh-syntax-highlighting", defer:2
zplug "b4b4r07/zsh-vimode-visual", defer:3

zplug "mafredri/zsh-async", defer:0
zplug "sindresorhus/pure", use:"pure.zsh", as:theme

zplug "$HOME/dotfiles/zsh/modules", from:local, \
	use:"{alias,docker,fuzzy,history}.zsh"
zplug "$HOME/dotfiles/zsh/modules", from:local, \
	use:"completions.zsh", defer:2

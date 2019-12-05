# Dotfiles

Dotfiles repo using a bare git-repo to manage them.

## Installation

Setup the dotfiles repo.

```sh
alias dots='/usr/bin/git --git-dir=$HOME/dotfiles/ --work-tree=$HOME'
echo "dotfiles" > $HOME/.gitignore
git clone --bare https://github.com/mbark/dotfiles $HOME/dotfiles
dots checkout
dots config --local status.showUntrackedFiles no
```

Install `dein` to manage packages on `vim`.
```sh
curl https://raw.githubusercontent.com/Shougo/dein.vim/master/bin/installer.sh > installer.sh
sh ./installer.sh ~/.vim
```

Install `brew` and install necessary packages.

```sh
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew bundle install --global
```



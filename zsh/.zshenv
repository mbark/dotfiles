export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/sbin"
export PATH="/Library/TeX/texbin:$PATH"
export PATH="$HOME/.cargo/bin:$PATH"
export PATH="$HOME/bin:$PATH"
export PATH="$PATH:/usr/bin/core_perl"

export MANPATH="/usr/local/man:$MANPATH"

export RUST_SRC_PATH="$HOME/dotfiles/dependencies/rust/src"
export ECLIPSE_HOME="/Applications/Eclipse.app/Contents/Eclipse"

# export ZPLUG_HOME="/usr/local/opt/zplug"
export ZPLUG_HOME="/usr/share/zsh/scripts/zplug"

FZF_PATH="/usr/local/opt/fzf/"
if [[ ! "$PATH" == *$"FZF_PATH/bin"* ]]; then
    export PATH="$PATH:$FZF_PATH/bin"
fi

if [[ ! "$MANPATH" == *"$FZF_PATH/man"* && -d "$FZF_PATH/man" ]]; then
    export MANPATH="$MANPATH:$FZF_PATH/man"
fi

if [ $(uname) == "Darwin" ] ; then
    source ~/workspace/monorepo/docker-alias.sh
else
    source ~/repos/monorepo/docker-alias.sh
fi

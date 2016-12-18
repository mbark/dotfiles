export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/sbin"
export PATH="/Library/TeX/texbin:$PATH"
export PATH="$HOME/.cargo/bin:$PATH"

export MANPATH="/usr/local/man:$MANPATH"

export RUST_SRC_PATH="$HOME/dotfiles/rust/src"
export ECLIPSE_HOME="/Applications/Eclipse.app/Contents/Eclipse"

export ZPLUG_HOME="/usr/local/opt/zplug"

if [[ ! "$PATH" == */usr/local/opt/fzf/bin* ]]; then
    export PATH="$PATH:/usr/local/opt/fzf/bin"
fi

if [[ ! "$MANPATH" == */usr/local/opt/fzf/man* && -d "/usr/local/opt/fzf/man" ]]; then
    export MANPATH="$MANPATH:/usr/local/opt/fzf/man"
fi

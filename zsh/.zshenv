export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/sbin"
export PATH="/Library/TeX/texbin:$PATH"
export PATH="$HOME/.cargo/bin:$PATH"
export PATH="$HOME/bin:$PATH"

export MANPATH="/usr/local/man:$MANPATH"

export RUST_SRC_PATH="$HOME/dotfiles/dependencies/rust/src"
export ECLIPSE_HOME="/Applications/Eclipse.app/Contents/Eclipse"

if [[ $(uname) == "Darwin" ]] ; then
    FZF_PATH="/usr/local/opt/fzf/"
    export ZPLUG_HOME="/usr/local/opt/zplug"
else
    FZF_PATH="/usr/share/fzf"
    export ZPLUG_HOME="/usr/share/zsh/scripts/zplug"

    export PATH="$PATH:/usr/bin/core_perl"
fi

export PATH="$PATH:$FZF_PATH/bin"
export MANPATH="$MANPATH:$FZF_PATH/man"

export LC_ALL=en_US.UTF-8
export LANG=en_US.UTF-8

export XDG_CONFIG_HOME="$HOME/.config"

export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/sbin"
export PATH="$PATH:/Library/TeX/texbin"
export PATH="$PATH:$HOME/.cargo/bin"
export PATH="$PATH:$HOME/bin"
export PATH="$PATH:$HOME/.config/yarn/global/node_modules/.bin"

export GOPATH="$HOME/go"
export GOROOT="/usr/local/opt/go/libexec"
export PATH="$PATH:$GOPATH/bin:$GOROOT/bin"

export MANPATH="/usr/local/man:$MANPATH"

export RUST_SRC_PATH="$HOME/.rustup/toolchains/stable-x86_64-apple-darwin/lib/rustlib/src/rust/src"

if [ -f "/usr/libexec/java_home" ] ; then
    export JAVA_HOME="$(/usr/libexec/java_home -v 1.8)"
fi

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

skip_global_compinit=1

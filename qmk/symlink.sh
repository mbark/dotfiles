#!/usr/bin/env bash
set -e
set -o pipefail

QMK="$HOME/repos/qmk_firmware"

if [ ! -d "$QMK" ] ; then
    cd "$HOME/repos" && git clone https://github.com/qmk/qmk_firmware
fi

create_symlinks() {
    FROM="$HOME/dotfiles/qmk/$1"
    TO="$QMK/keyboards/$1/keymaps/barkis"
    mkdir -p "$TO"

    echo "--> Symlinking $1"
    ln -sf "$FROM/keymap.c" "$TO/keymap.c"
    ln -sf "$FROM/rules.mk" "$TO/rules.mk"
}

create_symlinks ergodox_ez
create_symlinks planck

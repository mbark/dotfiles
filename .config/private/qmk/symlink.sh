#!/usr/bin/env bash
set -e
set -o pipefail

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"
QMK="$HOME/repos/qmk_firmware"

if [ ! -d "$QMK" ] ; then
    (cd "$HOME/repos" && git clone https://github.com/qmk/qmk_firmware)
fi

create_symlinks() {
    FROM="$SCRIPTPATH/$1"
    TO="$QMK/keyboards/$1/keymaps/barkis"
    mkdir -p "$TO"

    echo "--> Symlinking $1"
    ln -sf "$FROM/keymap.c" "$TO/keymap.c"
    ln -sf "$FROM/rules.mk" "$TO/rules.mk"
    if [ -f "$FROM/config.h"  ] ; then
        ln -sf "$FROM/config.h" "$TO/config.h"
    fi
}

create_symlinks ergodox_ez
create_symlinks planck

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
    if [ -f "$FROM/rules.mk"  ] ; then
        ln -sf "$FROM/rules.mk" "$TO/rules.mk"
    fi
    if [ -f "$FROM/config.h"  ] ; then
        ln -sf "$FROM/config.h" "$TO/config.h"
    fi
    if [ -f "$FROM/rgb_matrix_user.inc"  ] ; then
        ln -sf "$FROM/rgb_matrix_user.inc" "$TO/rgb_matrix_user.inc"
    fi
}

# A second keymap, barkis_<variant>, built from the same keymap.c with the
# rules.mk and config.h of the variant's subdirectory
create_variant_symlinks() {
    FROM="$SCRIPTPATH/$1"
    TO="$QMK/keyboards/$1/keymaps/barkis_$2"
    mkdir -p "$TO"

    echo "--> Symlinking $1 ($2)"
    ln -sf "$FROM/keymap.c" "$TO/keymap.c"
    ln -sf "$FROM/$2/rules.mk" "$TO/rules.mk"
    ln -sf "$FROM/$2/config.h" "$TO/config.h"
    if [ -f "$FROM/rgb_matrix_user.inc"  ] ; then
        ln -sf "$FROM/rgb_matrix_user.inc" "$TO/rgb_matrix_user.inc"
    fi
}

create_symlinks ergodox_ez
create_symlinks planck
create_symlinks lily58
create_symlinks boardsource/lulu
create_variant_symlinks boardsource/lulu noled

#!/usr/bin/env bash
# Builds the firmware for one half of the Lulu and copies it on once that half
# is in the bootloader. The halves take different builds (see CLAUDE.md), so
# the half has to be named.
set -e
set -o pipefail

QMK="$HOME/repos/qmk_firmware"
VOLUME="/Volumes/RPI-RP2"

case "$1" in
    left)
        KEYMAP="barkis"
        KEY="top-left key (Del/fn)"
        ;;
    right)
        KEYMAP="barkis_right"
        KEY="top-right key (-)"
        ;;
    *)
        echo "usage: $0 left|right" >&2
        exit 1
        ;;
esac
UF2="$QMK/boardsource_lulu_rp2040_$KEYMAP.uf2"

if [ ! -d "$QMK/keyboards/boardsource/lulu/keymaps/$KEYMAP" ] ; then
    echo "keymap $KEYMAP is not linked into $QMK, run symlink.sh first" >&2
    exit 1
fi

echo "--> Building $KEYMAP"
(cd "$QMK" && qmk compile -kb boardsource/lulu/rp2040 -km "$KEYMAP")

echo "--> Waiting for the $1 half's bootloader"
echo "    Unplug USB and the TRRS cable, then hold the $KEY while plugging"
echo "    USB into the $1 half. Or flip its BOOT switch on before plugging in."
DEADLINE=$(( $(date +%s) + 600 ))
until [ -f "$VOLUME/INFO_UF2.TXT" ] ; do
    if [ "$(date +%s)" -ge "$DEADLINE" ] ; then
        echo "gave up after 10 minutes, nothing was flashed" >&2
        exit 1
    fi
    sleep 1
done

echo "--> Copying $(basename "$UF2")"
# -X leaves extended attributes behind, which the drive can't store. GNU cp,
# first in PATH on this machine, doesn't have the flag.
/bin/cp -X "$UF2" "$VOLUME/"

# The half restarts once the file is written, which takes the drive away
for _ in $(seq 1 30) ; do
    [ -d "$VOLUME" ] || break
    sleep 1
done
if [ -d "$VOLUME" ] ; then
    echo "the drive is still mounted after 30 s, the copy may not have taken" >&2
    exit 1
fi

# With the BOOT switch on, the half comes straight back as the drive
sleep 5
if [ -d "$VOLUME" ] ; then
    echo "--> Flashed the $1 half. It is back in the bootloader: unplug it,"
    echo "    flip its BOOT switch off and plug it in again."
else
    echo "--> Flashed the $1 half"
fi

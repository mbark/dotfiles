#!/usr/bin/env bash

set -e
set -o pipefail

cd "$HOME/repos/qmk_firmware"
make ergodox_ez:barkis planck:barkis

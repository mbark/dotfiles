#!/usr/bin/env bash
set -e
set -o pipefail

qmk compile -kb ergodox_ez -km barkis

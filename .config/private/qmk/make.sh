#!/usr/bin/env bash
set -e
set -o pipefail

qmk compile -kb lily58 -km barkis -e CONVERT_TO=blok

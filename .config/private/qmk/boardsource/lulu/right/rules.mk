# The build for the right half: the barkis keymap with the link on the right
# half's pin (config.h) and without the display driver, since from 2026-10-02
# the right display freezes the half at start-up. barkis itself goes on the
# left half.
include $(dir $(lastword $(MAKEFILE_LIST)))../barkis/rules.mk

OLED_ENABLE = no

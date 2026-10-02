# The barkis keymap without the display driver, for the right half: since
# 2026-10-02 its display freezes the half at start-up as soon as the driver
# talks to it. Flash this to the right half and barkis to the left.
include $(dir $(lastword $(MAKEFILE_LIST)))../barkis/rules.mk

OLED_ENABLE = no

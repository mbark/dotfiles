# QMK keymaps

Keymap sources for four boards: the Boardsource Lulu (RP2040), `ergodox_ez`,
`lily58` and `planck`. The Lulu is the one with recent work and the notes
below.

## How the sources reach QMK

QMK is checked out at `~/repos/qmk_firmware`. `symlink.sh` links each
directory here into the checkout as a keymap called `barkis`, and clones the
checkout if it is missing. Run it again after adding a file to a keymap: it
only links `keymap.c`, `rules.mk`, `config.h` and `rgb_matrix_user.inc`.

Build with:

```sh
qmk compile -kb boardsource/lulu/rp2040 -km barkis        # left half
qmk compile -kb boardsource/lulu/rp2040 -km barkis_noled  # right half, see below
qmk compile -kb ergodox_ez -km barkis
```

The `.uf2` or `.hex` lands in the checkout root. `qmk config user.qmk_home`
points at the checkout; if a build can't find the keyboard, check that first.

## The Lulu

A split board: two halves joined by a TRRS cable, each with its own RP2040,
display and LEDs. Both halves run the same keymap.

- **USB goes in the left half.** The firmware has no handedness setting, so
  whichever half has USB acts as the left. A right half plugged in alone works,
  but types the left-hand keys.
- **Unplug USB before plugging or unplugging the TRRS cable.** The plug shorts
  power to the data contacts as it slides, which can kill a half.
- The layers mirror the ErgoDox keymap so that switching boards doesn't move
  any keys. A layer change on one should be made on the other.

### Layers

`keymap.c` has a diagram of each layer. In short:

| Key | Tap | Hold |
|---|---|---|
| Top-left | Del | fn layer: F-keys on the right hand |
| Beneath Tab | Esc | nav layer: arrows on HJKL, volume and media |
| Left thumb, innermost | | symbol layer: brackets and a numpad on the right hand |
| Left inner key (`SWE`) | toggle the Swedish layer (å ä ö) | Swedish layer while held |

On the fn, nav and symbol layers the left home row A S D F is Shift, Ctrl,
Alt, GUI. Symbol and fn together give the lighting controls. The Swedish
letters are sent as Option sequences, so they assume the macOS US layout.

### Displays and lighting

- Left display: a `SWE` marker while the Swedish layer is on, and the held
  modifiers.
- Right display: a map of the right-hand keys on the active layer, drawn from
  the keymap itself. **Not in use at the moment**, see "Right display" below.
- Keys light on press in a left-to-right rainbow that fades out
  (`rgb_matrix_user.inc`).

### Flashing

Each half is flashed separately, with USB plugged straight into that half.

1. Put the half into the bootloader. It mounts as `/Volumes/RPI-RP2`.
   - Hold the top outer key of that half while plugging USB in (Del/fn on the
     left, `-` on the right). This also resets the half's saved settings.
   - Or flip the BOOT toggle on the back before plugging in. This works even
     when the firmware doesn't start. Flip it back afterwards, otherwise the
     half returns to the bootloader on every power-up. The small push button
     next to it is RESET only.
2. Copy the firmware: `/bin/cp -X <file>.uf2 /Volumes/RPI-RP2/`. Plain `cp` on
   this machine is GNU cp, which has no `-X`.
3. The drive disappears and the half restarts into the new firmware.

Which halves need flashing:

- A change to the keys only: the left half. It decides what every key sends.
- A change to the right display, the lighting, or any `SPLIT_*` define or
  feature flag: both halves. Halves built with different split settings stop
  talking to each other, and the right half's keys go dead.

When flashing from Claude, a background loop that waits for
`/Volumes/RPI-RP2/INFO_UF2.TXT`, copies the file and reports back saves a
round trip per half.

### Right display (broken since 2026-10-02)

The right half's display, or its connection, failed overnight while the board
sat plugged in. Any firmware built with the display driver freezes that half
at start-up; the same keymap without the driver runs fine. A frozen half looks
dead: no keys over TRRS, and nothing on USB.

Until the display is reseated or replaced, the right half runs `barkis_noled`:
the same keymap with `OLED_ENABLE = no`, defined in `boardsource/lulu/noled/`.
It includes the main `rules.mk` and `config.h`, so the two builds stay
compatible. The left half keeps the full `barkis` build.

To go back: fix the display, flash `barkis` to the right half, and check that
it comes up on USB by itself before reconnecting TRRS. Then `noled/` and its
line in `symlink.sh` can go.

## Debugging a half that won't come up

What worked on 2026-10-02, in the order that narrows fastest.

**1. Read the Mac's USB log** rather than guessing from the keyboard:

```sh
/usr/bin/log show --last 5m --style compact --predicate \
  'process == "kernel" AND eventMessage CONTAINS "usb-drd"'
```

(`log` alone is a shell builtin in the Bash tool's zsh.) What the lines mean:

| Log line | Meaning |
|---|---|
| `enumerated 0x4273/7685 (lulu)` | firmware is up |
| `enumerated 0x2e8a/0003 (RP2 Boot)` | bootloader is up |
| `cableChangeOccurred: powering on`, then nothing | the half has power but never started USB |
| `createDevice: failed`, `persistent enumeration failures` | firmware started, then froze |

Both halves report the same IDs, so the log can't say which half is plugged in.

**2. Try the bootloader** with the BOOT toggle. If `RPI-RP2` mounts, the
processor, USB port and cable are fine, and the problem is in what the firmware
does at start-up.

**3. Rule out the flash contents.** Flashing a `.uf2` leaves the saved-settings
area alone. Raspberry Pi's `flash_nuke.uf2`
(`https://datasheets.raspberrypi.com/soft/flash_nuke.uf2`) erases everything; it
takes about a minute, after which the bootloader drive comes back and the
firmware can be copied on. It runs from memory, so if it works the processor
is fine even when no flashed firmware starts.

**4. Bisect the features.** Build a throwaway keymap in the checkout with
`OLED_ENABLE`, `RGB_MATRIX_ENABLE` and `ENCODER_ENABLE` set to `no`, then turn
them back on one at a time. The Lulu's `lib/oled.c` is compiled even with the
display driver off, so such a build needs the no-op `oled_write_raw_P` from
`boardsource/lulu/noled/config.h`.

Things that were ruled out along the way, and are worth ruling out first next
time:

- macOS "Allow accessories to connect" set to "Ask for New Accessories". The
  approval prompt holds the device longer than the firmware waits for USB
  (2 s), so the half decides it is the secondary one and drops off. It must be
  "Automatically When Unlocked".
- The BOOT toggle left on, which shows up as `RP2 Boot` in the log.

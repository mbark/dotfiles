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
qmk compile -kb boardsource/lulu/rp2040 -km barkis_right  # right half
qmk compile -kb ergodox_ez -km barkis
```

The `.uf2` or `.hex` lands in the checkout root. `qmk config user.qmk_home`
points at the checkout; if a build can't find the keyboard, check that first.

## The Lulu

A split board: two halves joined by a TRRS cable, each with its own RP2040,
display and LEDs.

- **The halves take different firmware**: `barkis` on the left, `barkis_right`
  on the right. This is a workaround for two hardware faults, see "Hardware
  faults" below. With the files swapped the halves don't talk, and the right
  half freezes at start-up.
- **USB goes in the left half.** The firmware has no handedness setting, so
  whichever half has USB acts as the left.
- **Unplug USB before plugging or unplugging the TRRS cable.** The plug shorts
  power to the data contacts as it slides, which can damage a pin.
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
  the keymap itself. **Switched off at the moment**, see "Hardware faults".
- Keys light on press in a left-to-right rainbow that fades out
  (`rgb_matrix_user.inc`).

### Flashing

Each half is flashed separately, with USB plugged straight into that half and
the TRRS cable unplugged.

1. Put the half into the bootloader. It mounts as `/Volumes/RPI-RP2`.
   - Hold the top outer key of that half while plugging USB in (Del/fn on the
     left, `-` on the right). This also resets the half's saved settings.
   - Or flip the BOOT toggle on the back before plugging in. This works even
     when the firmware doesn't start. Flip it back afterwards, otherwise the
     half returns to the bootloader on every power-up. The small push button
     next to it is RESET only.
2. Copy that half's file: `/bin/cp -X <file>.uf2 /Volumes/RPI-RP2/`. Plain `cp`
   on this machine is GNU cp, which has no `-X`.
3. The drive disappears and the half restarts into the new firmware.

Which halves need flashing:

- A change to the keys only: the left half. It decides what every key sends.
- A change to the right display, the lighting, or any `SPLIT_*` or `SERIAL_*`
  define or feature flag: both halves. Halves built with different link
  settings stop talking to each other, and the right half's keys go dead.

When flashing from Claude: the Mac cannot tell the halves apart, in the
bootloader or out of it. A background loop that copies a file as soon as
`RPI-RP2` mounts is fine for one half. For two halves with different files, have
the user say which half is in and copy by hand; a loop that takes "second
mount" to mean "the other half" put the left build on the right half once,
when the right half re-entered the bootloader with its BOOT toggle still on.

### Hardware faults (both since 2026-10-02)

The board sat plugged in overnight and the right side was dead in the morning.
Two separate faults turned up. What caused them isn't known.

**The right display freezes the right half.** Any firmware built with the
display driver freezes that half at start-up; the same keymap without the
driver runs fine. A frozen half looks dead: no keys over TRRS, and nothing on
USB. So `barkis_right` is built with `OLED_ENABLE = no`.

**The left half's receive pin (GP1) is stuck low.** The board's stock link
uses two wires, one per direction. The wire into the left half's GP1 is held
low, so the left half could send to the right but never hear it. The other
wire, joining GP0 on the left half to GP1 on the right, is fine. The link now
runs over that wire alone in single-wire mode: `config.h` undefines
`SERIAL_USART_FULL_DUPLEX`, and `right/config.h` moves the right half's end
to GP1.

Consequences:

- Stock or `default` firmware won't link the halves, since it expects both
  wires.
- There is no spare wire. If this one goes, the halves can only be used apart.
- Single-wire mode leans on the chip's weak internal pull-ups. If right-hand
  keys start dropping or sticking, try `#define SELECT_SOFT_SERIAL_SPEED 2` (or
  higher, which is slower) in `config.h`, and flash both halves.

To undo either workaround: for the display, reseat or replace the module
(0.91" 128x32 SSD1306, I2C), drop `OLED_ENABLE = no` from `right/rules.mk`,
flash the right half and check that it comes up on USB by itself. For the pin,
only a repair to the left half would help.

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
`boardsource/lulu/right/config.h`.

## Debugging a link that won't come up

When each half works alone on USB but the half without USB is dead:

**1. Put the same build on both halves.** If the link is still dead, it isn't a
settings mismatch.

**2. Measure the wires from the firmware.** Build a throwaway keymap that
includes `../barkis/keymap.c`, sets `CONSOLE_ENABLE = yes`, and in
`housekeeping_task_user`, on the half that has USB, once a second:

- reads each link pin ten times with the pull-down on
  (`gpio_set_pin_input_low`), then with the pull-up on
  (`gpio_set_pin_input_high`), and
- prints the counts with `uprintf`.

Read it on the Mac with `qmk console`. Wait a few seconds after start-up before
the first read, since reading takes the pins away from the link driver. Take
readings from each half in turn, without the cable and then with it:

| Reading | Meaning |
|---|---|
| low with pull-down, high with pull-up | nothing drives the line (normal with no cable) |
| high with both | the other half is driving or pulling it up (normal with the cable in) |
| low with both | the line is stuck low: a damaged pin or a short |

On 2026-10-02 the left half's GP1 read low with both pulls and no cable
attached, and the right half saw the same wire low through the cable.

## Ruled out before, worth ruling out first next time

- macOS "Allow accessories to connect" set to "Ask for New Accessories". The
  approval prompt holds the device longer than the firmware waits for USB
  (2 s), so the half decides it is the secondary one and drops off. It must be
  "Automatically When Unlocked".
- The BOOT toggle left on, which shows up as `RP2 Boot` in the log.
- The TRRS cable not pushed fully home.

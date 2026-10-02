#pragma once

// A single tap of SWE toggles the Swedish layer
#define TAPPING_TOGGLE 1

// A key pressed and released while Esc/nav or Del/fn is down counts as a
// hold, even inside the tapping term, so a quick arrow or F-key press doesn't
// send Esc or Del instead
#define PERMISSIVE_HOLD

// The halves talk over one wire instead of the board's usual two. Since
// 2026-10-02 the left half's receive pin (GP1) is stuck low, which kills the
// second wire. The wire that still works joins GP0 on the left half to GP1 on
// the right, so the right half's build (right/config.h) moves its end there.
#undef SERIAL_USART_FULL_DUPLEX

// The right half draws a map of the active layer and sleeps its display along
// with the left one, so it needs to know the layer and the last keypress
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_ACTIVITY_ENABLE

// Track keypresses for the lighting, and start in the effect from
// rgb_matrix_user.inc. The default only applies after an EEPROM reset, which
// entering the bootloader by holding the top-left key does.
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_RAINBOW_REACTIVE

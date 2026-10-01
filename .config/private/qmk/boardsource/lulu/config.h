#pragma once

// A single tap of SWE toggles the Swedish layer
#define TAPPING_TOGGLE 1

// A key pressed and released while Esc/nav or Del/fn is down counts as a
// hold, even inside the tapping term, so a quick arrow or F-key press doesn't
// send Esc or Del instead
#define PERMISSIVE_HOLD

// The right half draws a map of the active layer and sleeps its display along
// with the left one, so it needs to know the layer and the last keypress
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_ACTIVITY_ENABLE

// Track keypresses for the lighting, and start in the effect from
// rgb_matrix_user.inc. The default only applies after an EEPROM reset, which
// entering the bootloader by holding the top-left key does.
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_RAINBOW_REACTIVE

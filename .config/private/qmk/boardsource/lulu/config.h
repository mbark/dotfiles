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

// Copyright 2021 (@dbrglc)
// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
  _QWERTY,
  _SWEDISH,
  _SYMBOL,
  _FN,
  _NAVIGATION,
  _ADJUST,
};

enum custom_keycodes {
  SWE_AA = SAFE_RANGE, // å
  SWE_AE,              // ä
  SWE_OE,              // ö
};

// Tap toggles the Swedish layer, hold enables it while held (see TAPPING_TOGGLE)
#define SWE TT(_SWEDISH)
#define SYM MO(_SYMBOL)
// Tap for Esc, hold for the navigation layer
#define ESC_NAV LT(_NAVIGATION, KC_ESC)
// Tap for Del, hold for the function layer
#define DEL_FN LT(_FN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Del/fn|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Esc/nav|  A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  SWE  |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LAlt | LGUI | / SYM   /       \Enter \  |Space |BackSP| RAlt  |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  DEL_FN,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  ESC_NAV,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, SWE,      KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                             KC_LCTL, KC_LALT, KC_LGUI, SYM,      KC_ENT,  KC_SPC,  KC_BSPC, KC_RALT
),
/* SWEDISH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |   ö  |  ä   |
 * |------+------+------+------+------+------|  SWE  |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |       |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */

[_SWEDISH] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, SWE_AA,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, SWE_OE,  SWE_AE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   (  |   7  |   8  |   9  |   )  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Shift | Ctrl | Alt  | GUI  |      |-------.    ,-------|   [  |   4  |   5  |   6  |   ]  |  \   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   {  |   1  |   2  |   3  |   }  |  `   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | / SYM   /       \      \  |   0  |      |       |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */

[_SYMBOL] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   KC_LPRN, KC_7,    KC_8,    KC_9,    KC_RPRN, KC_MINS,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                   KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_1,    KC_2,    KC_3,    KC_RCBR, KC_GRV,
                             _______, _______, _______, _______, _______,  KC_0,    _______, _______
),
/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  fn  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |Shift | Ctrl | Alt  | GUI  |      |-------.    ,-------|      |  F4  |  F5  |  F6  | F11  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  F1  |  F2  |  F3  | F12  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |       |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */

[_FN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      | Vol+ | Mute |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | nav  |Shift | Ctrl | Alt  | GUI  |      |-------.    ,-------| Left | Down |  Up  |Right | Play | Next |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      | Vol- |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |       |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAVIGATION] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_VOLU, KC_MUTE,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_MNXT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* ADJUST (SYM + FN)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LAlt | LGUI | / SYM   /       \Enter \  |Space |BackSP| RAlt  |
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''--------------------'
 */

  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RM_NEXT, RM_HUED, RM_SATD, RM_VALD,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMBOL, _FN, _ADJUST);
}

// ä and ö are typed as Option+U followed by the letter, which assumes the
// macOS US layout. Option+U is only a dead key without Shift, so the held
// mods are dropped for it and restored for the letter.
static void tap_umlaut(uint8_t letter) {
  const uint8_t mods = get_mods();
  clear_mods();
  tap_code16(A(KC_U));
  set_mods(mods);
  tap_code(letter);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case SWE_AA:
        tap_code16(A(KC_A));
        return false;
      case SWE_AE:
        tap_umlaut(KC_A);
        return false;
      case SWE_OE:
        tap_umlaut(KC_O);
        return false;
    }
  }
  return true;
}

#ifdef OLED_ENABLE

// The displays stand upright, 32 px wide and 128 px tall, so both are turned
// to portrait: 5 characters by 16 lines of the stock font
#define OLED_WIDTH 32

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

// Left display: whether the Swedish layer is toggled on, and the held
// modifiers in the order they sit on the home row
static void render_status(void) {
  const bool    swedish = IS_LAYER_ON(_SWEDISH);
  const uint8_t mods    = get_mods() | get_oneshot_mods();

  oled_set_cursor(0, 0);
  oled_write_P(PSTR("     "), swedish);
  oled_write_P(swedish ? PSTR(" SWE ") : PSTR("     "), swedish);
  oled_write_P(PSTR("     "), swedish);

  oled_set_cursor(0, 5);
  oled_write_P(PSTR("SHIFT"), mods & MOD_MASK_SHIFT);
  oled_set_cursor(0, 7);
  oled_write_P(PSTR("CTRL "), mods & MOD_MASK_CTRL);
  oled_set_cursor(0, 9);
  oled_write_P(PSTR(" ALT "), mods & MOD_MASK_ALT);
  oled_set_cursor(0, 11);
  oled_write_P(PSTR(" GUI "), mods & MOD_MASK_GUI);
}

// Right display: a map of what the right-hand keys do on the active layer.
// Six columns have to fit in 32 px, which the stock 6 px font can't do, so the
// map has its own narrow font, drawn at double height.
#define GLYPH_HEIGHT 7
#define GLYPH_SCALE 2

typedef struct {
  char    id;
  uint8_t width;
  uint8_t rows[GLYPH_HEIGHT]; // top to bottom, the lowest `width` bits, leftmost pixel highest
} glyph_t;

// Lowercase ids are icons rather than letters
static const glyph_t glyphs[] = {
  {'0', 4, {0b0110, 0b1001, 0b1001, 0b1001, 0b1001, 0b1001, 0b0110}},
  {'1', 3, {0b010, 0b110, 0b010, 0b010, 0b010, 0b010, 0b111}},
  {'2', 4, {0b0110, 0b1001, 0b0001, 0b0010, 0b0100, 0b1000, 0b1111}},
  {'3', 4, {0b1110, 0b0001, 0b0001, 0b0110, 0b0001, 0b0001, 0b1110}},
  {'4', 4, {0b1001, 0b1001, 0b1001, 0b1111, 0b0001, 0b0001, 0b0001}},
  {'5', 4, {0b1111, 0b1000, 0b1110, 0b0001, 0b0001, 0b1001, 0b0110}},
  {'6', 4, {0b0110, 0b1000, 0b1000, 0b1110, 0b1001, 0b1001, 0b0110}},
  {'7', 4, {0b1111, 0b0001, 0b0001, 0b0010, 0b0010, 0b0100, 0b0100}},
  {'8', 4, {0b0110, 0b1001, 0b1001, 0b0110, 0b1001, 0b1001, 0b0110}},
  {'9', 4, {0b0110, 0b1001, 0b1001, 0b0111, 0b0001, 0b0001, 0b0110}},
  {'(', 2, {0b01, 0b10, 0b10, 0b10, 0b10, 0b10, 0b01}},
  {')', 2, {0b10, 0b01, 0b01, 0b01, 0b01, 0b01, 0b10}},
  {'[', 2, {0b11, 0b10, 0b10, 0b10, 0b10, 0b10, 0b11}},
  {']', 2, {0b11, 0b01, 0b01, 0b01, 0b01, 0b01, 0b11}},
  {'{', 3, {0b011, 0b010, 0b010, 0b100, 0b010, 0b010, 0b011}},
  {'}', 3, {0b110, 0b010, 0b010, 0b001, 0b010, 0b010, 0b110}},
  {'-', 3, {0b000, 0b000, 0b000, 0b111, 0b000, 0b000, 0b000}},
  {'+', 3, {0b000, 0b000, 0b010, 0b111, 0b010, 0b000, 0b000}},
  {'\\', 3, {0b100, 0b100, 0b010, 0b010, 0b010, 0b001, 0b001}},
  {'`', 2, {0b10, 0b01, 0b00, 0b00, 0b00, 0b00, 0b00}},
  {'H', 3, {0b101, 0b101, 0b101, 0b111, 0b101, 0b101, 0b101}},
  {'S', 3, {0b011, 0b100, 0b100, 0b010, 0b001, 0b001, 0b110}},
  {'V', 3, {0b101, 0b101, 0b101, 0b101, 0b101, 0b101, 0b010}},
  {'l', 3, {0b000, 0b001, 0b010, 0b111, 0b010, 0b001, 0b000}},                // left
  {'d', 3, {0b010, 0b010, 0b010, 0b010, 0b010, 0b111, 0b010}},                // down
  {'u', 3, {0b010, 0b111, 0b010, 0b010, 0b010, 0b010, 0b010}},                // up
  {'r', 3, {0b000, 0b100, 0b010, 0b111, 0b010, 0b100, 0b000}},                // right
  {'s', 3, {0b001, 0b011, 0b111, 0b111, 0b111, 0b011, 0b001}},                // speaker
  {'x', 3, {0b000, 0b000, 0b101, 0b010, 0b101, 0b000, 0b000}},                // muted
  {'p', 4, {0b1000, 0b1100, 0b1110, 0b1111, 0b1110, 0b1100, 0b1000}},         // play
  {'n', 4, {0b1001, 0b1101, 0b1111, 0b1111, 0b1111, 0b1101, 0b1001}},         // next
  {'t', 3, {0b000, 0b101, 0b010, 0b111, 0b010, 0b101, 0b000}},                // toggle the lighting
  {'a', 4, {0b0110, 0b0000, 0b0110, 0b0001, 0b0111, 0b1001, 0b0111}},         // å
  {'e', 4, {0b1001, 0b0000, 0b0110, 0b0001, 0b0111, 0b1001, 0b0111}},         // ä
  {'o', 4, {0b1001, 0b0000, 0b0110, 0b1001, 0b1001, 0b1001, 0b0110}},         // ö
  {'.', 1, {0, 0, 0, 1, 0, 0, 0}},                                            // nothing on this key
  {'?', 3, {0b000, 0b000, 0b111, 0b111, 0b111, 0b000, 0b000}},                // a key without a label below
};

// The map is read from the keymap itself, so it can't drift from it; a keycode
// missing here shows up as a block until it is given a label
static const struct {
  uint16_t    keycode;
  const char *label;
} key_labels[] = {
  {KC_TRNS, "."},  {KC_NO, "."},
  {KC_1, "1"},     {KC_2, "2"},     {KC_3, "3"},     {KC_4, "4"},     {KC_5, "5"},
  {KC_6, "6"},     {KC_7, "7"},     {KC_8, "8"},     {KC_9, "9"},     {KC_0, "0"},
  {KC_F1, "1"},    {KC_F2, "2"},    {KC_F3, "3"},    {KC_F4, "4"},    {KC_F5, "5"},    {KC_F6, "6"},
  {KC_F7, "7"},    {KC_F8, "8"},    {KC_F9, "9"},    {KC_F10, "10"},  {KC_F11, "11"},  {KC_F12, "12"},
  {KC_LPRN, "("},  {KC_RPRN, ")"},  {KC_LBRC, "["},  {KC_RBRC, "]"},  {KC_LCBR, "{"},  {KC_RCBR, "}"},
  {KC_MINS, "-"},  {KC_BSLS, "\\"}, {KC_GRV, "`"},
  {KC_LEFT, "l"},  {KC_DOWN, "d"},  {KC_UP, "u"},    {KC_RGHT, "r"},
  {KC_VOLU, "+"},  {KC_VOLD, "-"},  {KC_MUTE, "sx"}, {KC_MPLY, "p"},  {KC_MNXT, "n"},
  {SWE_AA, "a"},   {SWE_AE, "e"},   {SWE_OE, "o"},
  {RM_TOGG, "t"},  {RM_NEXT, "n"},
  {RM_HUEU, "H+"}, {RM_HUED, "H-"}, {RM_SATU, "S+"}, {RM_SATD, "S-"}, {RM_VALU, "V+"}, {RM_VALD, "V-"},
};

static const char *key_label(uint8_t layer, uint8_t row, uint8_t col) {
  const uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col});
  for (uint8_t i = 0; i < ARRAY_SIZE(key_labels); i++) {
    if (key_labels[i].keycode == keycode) {
      return key_labels[i].label;
    }
  }
  return "?";
}

static const glyph_t *find_glyph(char id) {
  for (uint8_t i = 0; i < ARRAY_SIZE(glyphs); i++) {
    if (glyphs[i].id == id) {
      return &glyphs[i];
    }
  }
  return &glyphs[ARRAY_SIZE(glyphs) - 1];
}

static uint8_t label_width(const char *label) {
  uint8_t width = 0;
  for (; *label; label++) {
    width += find_glyph(*label)->width + 1;
  }
  return width - 1;
}

static void draw_label(const char *label, uint8_t x, uint8_t y) {
  for (; *label; label++) {
    const glyph_t *glyph = find_glyph(*label);
    for (uint8_t row = 0; row < GLYPH_HEIGHT * GLYPH_SCALE; row++) {
      for (uint8_t col = 0; col < glyph->width; col++) {
        if (glyph->rows[row / GLYPH_SCALE] & (1 << (glyph->width - 1 - col))) {
          oled_write_pixel(x + col, y + row, true);
        }
      }
    }
    x += glyph->width + 1;
  }
}

// Draws rows of labels as a grid spread over the width of the display, each
// column as wide as its widest label so the rows line up. Returns the y below
// the grid.
#define MAP_COLS 6
#define MAP_ROW_PITCH 24

static uint8_t draw_grid(const char *labels[][MAP_COLS], uint8_t rows, uint8_t cols, uint8_t y) {
  uint8_t widths[MAP_COLS] = {0};
  uint8_t total            = 0;
  for (uint8_t col = 0; col < cols; col++) {
    for (uint8_t row = 0; row < rows; row++) {
      widths[col] = MAX(widths[col], label_width(labels[row][col]));
    }
    total += widths[col];
  }

  const uint8_t spare = total < OLED_WIDTH ? OLED_WIDTH - total : 0;
  const uint8_t gap   = spare / (cols - 1);
  uint8_t       extra = spare % (cols - 1); // handed out a pixel at a time, from the left
  uint8_t       x     = 0;
  for (uint8_t col = 0; col < cols; col++) {
    for (uint8_t row = 0; row < rows; row++) {
      const char *label = labels[row][col];
      draw_label(label, x + (widths[col] - label_width(label)) / 2, y + row * MAP_ROW_PITCH);
    }
    x += widths[col] + gap;
    if (extra) {
      extra--;
      x++;
    }
  }
  return y + rows * MAP_ROW_PITCH;
}

static bool row_is_empty(const char *labels[MAP_COLS], uint8_t cols) {
  for (uint8_t col = 0; col < cols; col++) {
    if (labels[col][0] != '.') {
      return false;
    }
  }
  return true;
}

static void render_layer_map(uint8_t layer) {
  static const char *const titles[] = {
    [_SWEDISH] = " SWE ", [_SYMBOL] = " SYM ", [_FN] = " FN  ", [_NAVIGATION] = " NAV ", [_ADJUST] = " RGB ",
  };
  oled_set_cursor(0, 0);
  oled_write(titles[layer], false);

  // The right half is matrix rows 5 to 9 with its columns counted from the
  // outer edge. Rows 5 to 8 are the four rows of six, and row 9 holds the
  // thumb keys, Enter in column 4 out to RAlt in column 1.
  const char *keys[4][MAP_COLS];
  for (uint8_t row = 0; row < 4; row++) {
    for (uint8_t col = 0; col < MAP_COLS; col++) {
      keys[row][col] = key_label(layer, 5 + row, 5 - col);
    }
  }
  const char *thumbs[1][MAP_COLS];
  for (uint8_t col = 0; col < 4; col++) {
    thumbs[0][col] = key_label(layer, 9, 4 - col);
  }

  // The number row and the thumbs are left out when a layer has nothing on
  // them, which leaves the three letter rows easier to place at a glance
  const uint8_t first = row_is_empty(keys[0], MAP_COLS) ? 1 : 0;
  const uint8_t y     = draw_grid(&keys[first], 4 - first, MAP_COLS, 20);
  if (!row_is_empty(thumbs[0], 4)) {
    draw_grid(thumbs, 1, 4, y + 4);
  }
}

bool oled_task_user(void) {
  // The driver only puts a display to sleep once its picture stops changing,
  // which would blank the Swedish marker mid-sentence. Go by the last keypress
  // instead, which SPLIT_ACTIVITY_ENABLE shares with the right half.
  if (last_input_activity_elapsed() > OLED_TIMEOUT) {
    oled_off();
    return false;
  }
  oled_on();

  if (is_keyboard_master()) {
    render_status();
    return false;
  }

  static uint8_t shown = _QWERTY;
  const uint8_t  layer = get_highest_layer(layer_state);
  if (layer != shown) {
    shown = layer;
    oled_clear();
    if (layer != _QWERTY) {
      render_layer_map(layer);
    }
  }
  return false;
}

#endif

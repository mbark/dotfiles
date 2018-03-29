#include QMK_KEYBOARD_H
#include "debug.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#include "version.h"

// Make it easier to read the layouts
#define _______ KC_TRNS

// Combokeys
#define TAB_CTL MT(MOD_LCTL, KC_TAB)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define RIS_SPC LT(_RAISE, KC_SPC)

// Tab-modifier keys
#define CTL_FRW LCTL(KC_TAB)
#define CTL_BKW LSFT(LCTL(KC_TAB))
#define GUI_FRW LGUI(KC_TAB)
#define GUI_BKW LSFT(LGUI(KC_TAB))

// Modifier combos
#define LSH_GUI OSM(MOD_LSFT | MOD_LGUI)
#define RSH_GUI OSM(MOD_RSFT | MOD_RGUI)
#define LSH_ALT OSM(MOD_LSFT | MOD_LALT)
#define RSH_ALT OSM(MOD_LSFT | MOD_RALT)
#define LCT_ALT OSM(MOD_LCTL | MOD_LALT)
#define RCT_ALT OSM(MOD_RCTL | MOD_RALT)

// TODO: it is pretty dumb to have tap dance when you could just hold shift...
// Tap dances
#define TD_1 TD(_TD_1)
#define TD_2 TD(_TD_2)
#define TD_3 TD(_TD_3)
#define TD_4 TD(_TD_4)
#define TD_5 TD(_TD_5)
#define TD_6 TD(_TD_6)
#define TD_7 TD(_TD_7)
#define TD_8 TD(_TD_8)
#define TD_9 TD(_TD_9)
#define TD_EXLM TD(_TD_ELXM)
#define TD_AT (_TD_AT)
#define TD_HASH (_TD_HASH)
#define TD_DLR (_TD_DLR)
#define TD_PERC (_TD_PERC)
#define TD_CIRC (_TD_CIRC)
#define TD_AMPR (_TD_AMPR)
#define TD_ASTR (_TD_ASTR)
#define TD_BSLS (_TD_BSLS)
#define TD_PRN TD(_TD_PRN)
#define TD_BRC TD(_TD_BRC)
#define TD_CBR TD(_TD_CBR)

enum {
   _QWERTY,
   _LOWER,
   _RAISE,
   _NAVIGATION,
   _SUPERDUPER
};

enum keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};


// Combo : SuperDuper layer from S+D (R+S in Colemak)
#define SUPERDUPER_COMBO_COUNT 1
#define EECONFIG_SUPERDUPER_INDEX (uint8_t *) 19

enum {
    _TD_1,
    _TD_2,
    _TD_3,
    _TD_4,
    _TD_5,
    _TD_6,
    _TD_7,
    _TD_8,
    _TD_9,
    _TD_ELXM,
    _TD_AT,
    _TD_HASH,
    _TD_DLR,
    _TD_PERC,
    _TD_CIRC,
    _TD_AMPR,
    _TD_ASTR,
    _TD_BSLS,
    _TD_PRN,
    _TD_BRC,
    _TD_CBR,
};

enum process_combo_event {
  CB_SUPERDUPER,
};

const uint16_t PROGMEM superduper_combos[SUPERDUPER_COMBO_COUNT][3] = {
  [_QWERTY] = {KC_S, KC_D, COMBO_END},
};

combo_t key_combos[COMBO_COUNT] = {
  [CB_SUPERDUPER] = COMBO_ACTION(superduper_combos[_QWERTY]),
};


const uint16_t empty_combo[] = {COMBO_END};

void set_superduper_key_combos(void);
void clear_superduper_key_combos(void);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // TODO: enter and tab are essentially unnecessary here if we put them on the thumbs
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Esc   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   [ ]  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Tab/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Shift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | Sft/Ent|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      |      | Alt  | Cmd  |                                       | Cmd  |  Alt |      |      | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | LOWER|      |      |       |      |      |RAISE |
 *                                 | Bksp | Tab  |------|       |------|Enter |Space |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,
        TAB_CTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,
        RAISE,   KC_LCTL, _______, KC_LALT, KC_LGUI,

                                                                   _______, _______,
                                                                            _______,
                                                          LOW_BSP, KC_TAB,  _______,

        // right hand
        _______,   _______, _______, _______, _______, _______,  _______,
        _______,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     TD_BRC,
                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        _______,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SFT_ENT,
        KC_RGUI,   KC_RALT, _______, KC_RCTL, LOWER,

        _______, _______,
        _______,
        _______, KC_ENT,  RIS_SPC
    ),
/* Lower: Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ShGui  |      |  *   |  -   |  [ ] |  ]   |      |           |      |      |  7 & |  8 * |  9 ()|  ,   | ShGui  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ShAlt  |      |  /   |  +   |  ( ) |  )   |------|           |------|      |  4 $ |  5 % |  6 ^ |  .   | ShAlt  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CtAlt  |      |      |      |  { } |  }   |      |           |      |      |  1 ! |  2 @ |  3 # |      | CtAlt  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LOWER |      |------|       |------|      |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWER] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       LSH_GUI, _______, KC_ASTR, KC_MINS, TD_BRC,  KC_RBRC, _______,
       LSH_ALT, _______, KC_SLSH, KC_PLUS, TD_PRN,  KC_RPRN,
       LCT_ALT, _______, _______, _______, TD_CBR,  KC_RCBR, _______,
       _______, _______, _______, _______, _______,

                                                                     _______, _______,
                                                                              _______,
                                                            _______, _______, _______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, TD_7,    TD_8,    TD_9,    KC_COMM, LSH_GUI,
                _______, TD_4,    TD_5,    TD_6,    KC_DOT,  _______,
       _______, _______, TD_1,    TD_2,    TD_3,    _______, _______,
                         _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, KC_0
),
/* Raise: Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  ShGui |  & 7 |  * 8 |  \ 9 |  [ ] |   ]  |      |           |      |      |      |      |      |      | ShGui  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  ShAlt |  $ 4 |  % 5 |  ^ 6 |  ( ) |   )  |------|           |------|      |   -  |  `   |  =   |  \   | ShAlt  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CtAlt |  ! 1 |  @ 2 |  # 3 |  { } |   }  |      |           |      |      |   _  |  ~   |  +   |  |   | CtAlt  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |RAISE |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAISE] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, TD_AMPR, TD_ASTR, TD_BSLS, TD_BRC,  KC_RBRC, _______,
       _______, TD_DLR,  TD_PERC, TD_CIRC, TD_PRN,  KC_RPRN,
       _______, TD_EXLM, TD_AT,   TD_HASH, TD_CBR,  KC_RCBR, _______,
       _______, _______, _______, _______, _______,

                                                                       _______, _______,
                                                                                _______,
                                                              _______, _______, _______,

       // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, KC_MINS, KC_GRV,  KC_EQL,  KC_BSLS, _______,
       _______,  _______, KC_UNDS, KC_TILD, KC_PLUS, KC_PIPE, _______,
                          _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, _______
),
/* Navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |TbLeft| PgDn | PgUp |TbRght|      | Mute   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Shift| Ctrl | Alt  | Gui  |      |------|           |------| Left | Down |  Up  | Right|CmdTb | Play   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Bksp |Delete|      |      |           |      | Prev | Vol- | Vol+ | Next |CmdTbB|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | MsLC |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      | Shift|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NAVIGATION] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
    _______, _______, _______, KC_BSPC, KC_DEL,  _______, _______,
    _______, _______, _______, _______, _______,

                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, CTL_BKW, KC_PGDN, KC_PGUP, CTL_FRW, _______, KC_MUTE,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, GUI_FRW, KC_MNXT,
    _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, GUI_BKW, _______,
                      KC_BTN1, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, KC_RSFT
),
/* Superduper: FN-keys with modifiers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | F7   |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Alt  |[Super-Duper]| Gui  |      |------|           |------|      | F4   |  F5  |  F6  | F11  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | F1   |  F2  |  F3  | F12  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Shift |      |------|       |------|      | Ctrl |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SUPERDUPER] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LALT, _______, _______, KC_LGUI, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,

                                                             _______, _______,
                                                                      _______,
                                                    KC_LSFT, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11, 
    _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
    _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, KC_LCTL
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case _LOWER:
            // Binary 2 represented by the leds
            // -*-
            ergodox_right_led_2_on();
            break;
        case _RAISE:
            // Binary 3 represented by the leds
            // **-
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case _NAVIGATION:
            // Binary 4 represented by the leds
            // --*
            ergodox_right_led_3_on();
            break;
        case _SUPERDUPER:
            // Binary 5 represented by the leds
            // *-*
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }
};

//
/* Keymap N: Empty template
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
void set_superduper_key_combos(void) {
  uint8_t layer = eeprom_read_byte(EECONFIG_SUPERDUPER_INDEX);

  switch (layer) {
    case _QWERTY:
      key_combos[CB_SUPERDUPER].keys = superduper_combos[layer];
      break;
  }
}

void clear_superduper_key_combos(void) {
  key_combos[CB_SUPERDUPER].keys = empty_combo;
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  if (pressed) {
    switch(combo_index) {
      case CB_SUPERDUPER:
        layer_on(_SUPERDUPER);
        break;
    }
  } else {
    layer_off(_SUPERDUPER);
    unregister_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT)); // Sometimes mods are held, unregister them
  }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NAVIGATION);
      }
      return false;
      break;
  }
  return true;
}


void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

void shift_key(uint16_t keycode)
{
  register_code  (KC_LSFT);
  tap_key        (keycode);
  unregister_code(KC_LSFT);
}

void exclamation(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_1);
  }
  else {
    tap_key(KC_1);
  }
  reset_tap_dance(state);
}

void at(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_2);
  }
  else {
    tap_key(KC_2);
  }
  reset_tap_dance(state);
}


void hash(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_3);
  }
  else {
    tap_key(KC_3);
  }
  reset_tap_dance(state);
}

void dlr(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_4);
  }
  else {
    tap_key(KC_4);
  }
  reset_tap_dance(state);
}

void perc(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_5);
  }
  else {
    tap_key(KC_5);
  }
  reset_tap_dance(state);
}

void circ(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_6);
  }
  else {
    tap_key(KC_6);
  }
  reset_tap_dance(state);
}

void ampr(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_7);
  }
  else {
    tap_key(KC_7);
  }
  reset_tap_dance(state);
}

void astr(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_8);
  }
  else {
    tap_key(KC_8);
  }
  reset_tap_dance(state);
}

void bsls(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    shift_key(KC_9);
  }
  else {
    tap_key(KC_9);
  }
  reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [_TD_1]  = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
  [_TD_2]  = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
  [_TD_3]  = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
  [_TD_4]  = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
  [_TD_5]  = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
  [_TD_6]  = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
  [_TD_7]  = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
  [_TD_8]  = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
  [_TD_9]  = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
  [_TD_ELXM] = ACTION_TAP_DANCE_FN(exclamation),
  [_TD_AT]   = ACTION_TAP_DANCE_FN(at),
  [_TD_HASH] = ACTION_TAP_DANCE_FN(hash),
  [_TD_DLR]  = ACTION_TAP_DANCE_FN(dlr),
  [_TD_PERC] = ACTION_TAP_DANCE_FN(perc),
  [_TD_CIRC] = ACTION_TAP_DANCE_FN(circ),
  [_TD_AMPR] = ACTION_TAP_DANCE_FN(ampr),
  [_TD_ASTR] = ACTION_TAP_DANCE_FN(astr),
  [_TD_BSLS] = ACTION_TAP_DANCE_FN(bsls),
  [_TD_PRN]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [_TD_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [_TD_CBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
};

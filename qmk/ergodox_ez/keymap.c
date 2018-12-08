#include QMK_KEYBOARD_H
#include "debug.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#include "version.h"

// ==================== #defines for keycodes ====================
#define _______ KC_TRNS

// Combokeys
#define ESC_NAV LT(_NAVIGATION, KC_ESC)

// Layer toggling
#define SWE MO(_SWEDISH)
#define SYM MO(_SYMBOL)
#define NUM MO(_NUMPAD)
#define NAV MO(_NAVIGATION)
#define FN MO(_SWEDISH)

// ==================== enums ====================
// Layers
enum {
   _QWERTY,
   _SWEDISH,
   _SYMBOL,
   _NUMPAD,
   _NAVIGATION,
   _FN
};

// Macros
enum {
    _SWEO = SAFE_RANGE,
    _SWEA,
    _SWEAA,
};

// ==================== keyboard confiruation ====================
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |  (   |           |  )   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  tab   |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |  bspc  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |esc/nav |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * | shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ctrl | l-fn | swe  | alt  | gui  |                                       | gui  | alt  |   ←  |   →  | ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | l-sym| l-num|------|       |------| enter|  spc |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
        // left hand
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_LPRN,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,
        ESC_NAV, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LCBR,
        KC_LCTL, FN,       SWE, KC_LALT, KC_LGUI,

                                                                   _______, _______,
                                                                            _______,
                                                           SYM,    NUM,     _______,

        // right hand
        KC_RPRN,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
        KC_RBRC,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_RCBR,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
        KC_RGUI,   KC_RALT, KC_LEFT, KC_RGHT, KC_RCTL,

        _______, _______,
        _______,
        _______, KC_ENT,  KC_SPC
    ),
/* Swedish: for swedish characters
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |   ö  |   ä    |
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
[_SWEDISH] = LAYOUT_ergodox(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,

                                                                   _______, _______,
                                                                            _______,
                                                          _______, _______, _______,

        // right hand
        _______,   _______, _______, _______, _______, _______,  _______,
        _______,   _______, _______, _______, _______, _______,  _SWEA,
                   _______, _______, _______, _______, _SWEO,    _SWEAA,
        _______,   _______, _______, _______, _______, _______,  _______,
        _______,   _______, _______, _______, _______,

        _______, _______,
        _______,
        _______, _______,  _______
    ),
/* l-sym
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  &   |  *   |   (  |  )   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  sft | ctrl | alt  | cmd  |      |------|           |------|  `   |  $   |  %   |   ^  |  =   |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  ~   |  !   |  @   |  #   |  +   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | l-sym|      |------|       |------|   _  |   -  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SYMBOL] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,

                                                                     _______, _______,
                                                                              _______,
                                                            _______, _______, _______,
       // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                KC_GRV,  KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_BSLS,
       _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PLUS, _______,
                         _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, KC_UNDS, KC_MINS
),
/* l-num
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | sft  | ctrl |  alt |  cmd |      |------|           |------|      |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | l-num|------|       |------|      |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NUMPAD] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,

                                                                       _______, _______,
                                                                                _______,
                                                             _______,  _______, _______,

       // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_7,    KC_8,    KC_9,    _______, _______,
                 _______, KC_4,    KC_5,    KC_6,    _______, _______,
       _______,  _______, KC_1,    KC_2,    KC_3,    _______, _______,
                          _______, _______, _______, _______, _______,

       _______, _______,
       _______,
       _______, _______, KC_0
),
/* Navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MUp  |      |      |      |           |      |      |      |      |      | Vol+ |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  nav   |      | MLeft| MDown|MRight|      |------|           |------| Left | Down |  Up  | Right| Play | Next   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      | Vol- |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | MLeft|MRight|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_NAVIGATION] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MS_U, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,

                                                       _______, _______,
                                                                _______,
                                              _______, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_MNXT,
    _______, _______, _______, _______, _______, KC_VOLD, _______,
                      KC_BTN1, KC_BTN2, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, _______
),
/* l-fn: fn-keys with modifiers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | ctrl | alt  | cmd  |      |------|           |------|      |  F4  |  F5  |  F6  | F11  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F1  |  F2  |  F3  | F12  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | l-fn |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_FN] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LCTL, KC_LALT, KC_LCMD, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,

                                                             _______, _______,
                                                                      _______,
                                                    _______, _______, _______,
    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
             _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, 
    _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
    _______, _______, _______, _______, _______,

    _______, _______,
    _______,
    _______, _______, _______
),
};

// ==================== macros ====================
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case _SWEA:
                if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                    SEND_STRING(SS_LALT("A"));
                } else {
                    SEND_STRING(SS_LALT("a"));
                }
                return false;
            case _SWEAA:
                if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                    SEND_STRING(SS_LALT("u")"A");
                } else {
                    SEND_STRING(SS_LALT("u")"a");
                }
                return false;
            case _SWEO:
                if (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                    SEND_STRING(SS_LALT("u")"O");
                } else {
                    SEND_STRING(SS_LALT("u")"o");
                }
                return false;
        }
    }
    return true;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            // Binary 1 represented by the leds
            // -*-
            ergodox_right_led_1_on();
            break;
        case 2:
            // Binary 2 represented by the leds
            // -*-
            ergodox_right_led_2_on();
            break;
        case 3:
            // Binary 3 represented by the leds
            // **-
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 4:
            // Binary 4 represented by the leds
            // --*
            ergodox_right_led_3_on();
            break;
        case 5:
            // Binary 5 represented by the leds
            // *-*
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
        case 6:
            // Binary 5 represented by the leds
            // -**
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
        case 7:
            // Binary 5 represented by the leds
            // ***
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }
};

/* Keymap: Empty template
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

#include QMK_KEYBOARD_H
#include "debug.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#include "version.h"

#define GUI_SPC MT(MOD_RGUI, KC_SPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define FN_ESC  LT(NAV, KC_ESC)
#define FN_QUOT LT(NAV, KC_QUOT)

#define BASE 0
#define SWE 1
#define LOWER 2
#define RAISE 3
#define NAV 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | Enter  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      |      | Alt  | CMD  |                                       |LLower| LAlt |      |      | Ctrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |CMD/  |
 *                                 |LRaise|LLower|------|       |------|LRaise|Space |
 *                                 |      |      |TSweL |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_TRNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_TRNS,
        FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_TRNS,
        KC_LCTL, KC_TRNS, KC_TRNS, KC_LALT, KC_LGUI,

                                                                     KC_TRNS,   KC_TRNS,
                                                                                KC_TRNS,
                                                                     MO(RAISE), MO(LOWER), LSFT(LGUI(KC_SPC)),

        // right hand
        KC_TRNS,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
        KC_TRNS,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
                   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  FN_QUOT,
        KC_TRNS,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SFT_ENT,
        MO(LOWER), KC_LALT, KC_TRNS, TG(SWE), KC_RCTL,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, MO(RAISE), GUI_SPC
    ),
/* Keymap 1: Swedish layer (just for the Swedish characters)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      | TSweL|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,------------.
 *                                        |      |      |       |      |     |
 *                                 ,------|------|------|       |------+-----+------.
 *                                 |      |      |      |       |      |     |      |
 *                                 | Bksp |      |------|       |------|     |      |
 *                                 |      |      |      |       |      |     |      |
 *                                 `--------------------'       `-------------------'
 */
[SWE] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                           KC_TRNS, KC_TRNS,
                                                                                    KC_TRNS,
                                                                  KC_BSPC, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_AA,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_OSLH, NO_AE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Raise (symbols)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    ~   |   !  |   @  |   #  |   $  |   %  |      |           |      |  ^   |  &   |  *   |  (   |   )  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  -   |  =   |  [   |   ]  |      |------|           |------|  `   |  -   |  =   |  [   |   ]  |    \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  _   |  +   |  {   |   }  |      |      |           |      |  ~   |  _   |  +   |  {   |   }  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LRaise|      |------|       |------|LRaise|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RAISE] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
       KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                    KC_TRNS,  KC_TRNS,
                                                                              KC_TRNS,
                                                            KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
                KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
       KC_TRNS, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Lower (left-hand), number keys, numpad and special characters (same as lower)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   `    |  1   |  2   |  3   |  4   |  5   |      |           |      |   6  |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  -   |  =   |  [   |  ]   |      |------|           |------|   ,  |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  _   |  +   |  {   |  }   |      |      |           |      |   .  |  1   |  2   |  3   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |Llower|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |LLower|------|       |------|      |  0   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LOWER] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
       KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
       KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                                      KC_TRNS,  KC_TRNS,
                                                                                KC_TRNS,
                                                              KC_TRNS, KC_TRNS, KC_TRNS,

       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
                 KC_COMM, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_PIPE,
       KC_TRNS,  KC_DOT,  KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_0
),
/* Keymap 4: Navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |WWWBak| MUp  |WWWFwd|      |      |           |      |      |      |      | Next | Vol- |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LNav   |      |MLeft |MDown |MRight|      |------|           |------| Left | Down |  Up  | Right| Play |  LNav  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      | Mute | Vol+ |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |Mouse1|Mouse2|      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | CMD  | Alt  |------|       |------|      | Shift|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox(
    // left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_WBAK, KC_MS_U, KC_WFWD, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                       KC_TRNS, KC_TRNS,
                                                                KC_TRNS,
                                              KC_LGUI, KC_LALT, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLU, KC_TRNS,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_MNXT,
    KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_TRNS,
                      KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,

    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_RSFT
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
        case SWE:
            // Binary 1 represented by the leds
            // --*
            ergodox_right_led_3_on();
            break;
        case LOWER:
            // Binary 2 represented by the leds
            // -*-
            ergodox_right_led_2_on();
            break;
        case RAISE:
            // Binary 3 represented by the leds
            // -**
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();
            break;
        case NAV:
            // Binary 4 represented by the leds
            // *--
            ergodox_right_led_1_on();
            break;
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

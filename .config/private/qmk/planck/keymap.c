// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.
//
// Dropped the Dvorak layer and added two my layer buttons.  Both Raise and lower can be accessed from either side now.

#include "planck.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

// Makes tap and hold keys work better for fast typers who don't want tapping term set above 500
#define PERMISSIVE_HOLD

#define TAB_LWR LT(LOWER, KC_TAB)
#define GUI_SPC MT(MOD_RGUI, KC_SPC)
#define SFT_ENT MT(MOD_LSFT, KC_ENT)
#define FN_ENT  LT(RAISE, KC_ENT)
#define FN_ESC  LT(NAV, KC_ESC)
#define FN_QUOT LT(NAV, KC_QUOT)

#define MO_RS MO(RAISE)
#define MO_LWR MO(LOWER)

#define TGL_KB  LSFT(LGUI(KC_SPC))

#define BASE 0
#define SWE 1
#define LOWER 2
#define RAISE 3
#define NAV 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// It appears as if LGUI and LALT are messed up? This results in the shown keymap even though
// the codes are wrong
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | "/NV |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |LRaise|LLower|    Space    |LRaise|LLower| LAlt | LSwe | Ctrl |
 * `-----------------------------------------------------------------------------------'
*/
[BASE] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {FN_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, FN_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT},
  {KC_LCTL, KC_LGUI, KC_LALT, MO_RS,   MO_LWR,  KC_SPC,  KC_SPC,  MO_RS,   MO_LWR,  KC_RALT, TG(SWE), KC_RCTL}
},
/* Swedish
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  Ö   |  Ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Bksp |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
*/
[SWE] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_AA},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NO_OSLH, NO_AE},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
/* Raise (right hand): symbols
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |LRaise|      |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
/* Lower (left hand): number keys, numpad and special characters
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |  7   |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   -  |  =   |  [   |  ]   |      |   ,  |  4   |   5  |   6  |      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   _  |  +   |  {   |  }   |      |   .  |  1   |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |LLower|             |  0   |LLower|      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS, KC_COMM, KC_4,    KC_5,    KC_6,    KC_RBRC, KC_PIPE},
  {KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_DOT,  KC_1,    KC_2,    KC_3,    KC_RCBR, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |WWWBak|  MUp |WWWFwd|      |      |      |      | Next | Vol+ |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Btn1 | Btn2 |MLeft | MDown|MRight|      | Left | Down |  Up  | Right| Play |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LNav |      |      |      |      |      |      |      |      | Mute | Vol- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Alt  | CMD  |             | Shift|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[NAV] = {
  {KC_TRNS, KC_TRNS, KC_WBAK, KC_MS_U, KC_WFWD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLU, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_RSFT, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS}
}
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    } else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};

/* blank
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
*/
/* [_FN] = { */
/*   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
/*   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS} */
/* } */

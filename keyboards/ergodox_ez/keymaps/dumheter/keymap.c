#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

#define COLE 0   // base layer with colemak layout
#define SYMB 1   // symbols
#define QWERTY 2 // base layer with qwerty layout

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: cole
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | Esc    |  1!  |  2"@ |  3#£ |  4¤$ | 5%€  | '`   |           | "^~  | 6&   | 7/{  |  8([ |  9)] | 0=}  |  +?    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L2  |   J  |   L  |   U  |   Y  |   Ö  |   Å    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | LCtrl  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   Ä    |
   * |--------+------+------+------+------+------| Win  |           | Alt  |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           | Gr   |   K  |   M  |   ,; |   .: |   -_ | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | <>|  |  §½  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |Mute  | End  |       |ply/ps| next |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       |vol u |  Left  |      |
   *                                 | Space|Backsp|------|       |------|  Alt   |Enter |
   *                                 |      |ace   | Del  |       |vol d |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [COLE] = LAYOUT_ergodox
  (
   // left hand
   KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    NO_ACUT,
   KC_TAB,     KC_Q,     KC_W,     KC_F,     KC_P,    KC_G,    TG(SYMB),
   KC_LCTL,    KC_A,     KC_R,     KC_S,     KC_T,    KC_D,
   KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_LGUI,
   KC_NUBS,    KC_GRV,   LALT(KC_LSFT),      KC_LEFT, KC_RGHT,
   KC_MUTE,    KC_END,
   KC_HOME,
   KC_SPC,     KC_BSPC,  KC_DEL,
   // right hand
   NO_QUOT,    KC_6,     KC_7,     KC_8,     KC_9,    KC_0,     KC_MINS,
   TG(QWERTY), KC_J,     KC_L,     KC_U,     KC_Y,    NO_OSLH,  NO_AA,
   KC_H,       KC_N,     KC_E,     KC_I,     KC_O,    NO_AE,
   NO_ALGR,    KC_K,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
   KC_UP,      KC_DOWN,  KC_LBRC,  KC_RBRC,  KC_FN1,
   KC_MPLY,    KC_MNXT,
   KC_VOLU,
   KC_VOLD,    KC_LALT,  KC_ENT
   ),

  /* Keymap 1: Symbol Layer
   *
   * ,---------------------------------------------------.           ,--------------------------------------------------.
   * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
   * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
   *   `-----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |Animat|      |       |Toggle|Solid |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
   *                                 |ness- |ness+ |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // SYMBOLS
  [SYMB] = LAYOUT_ergodox
  (
   // left hand
   VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
   KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
   KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
   KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
   EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
   RGB_MOD,KC_TRNS,
   KC_TRNS,
   RGB_VAD,RGB_VAI,KC_TRNS,
   // right hand
   KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
   KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
   KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
   KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
   KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
   RGB_TOG, RGB_SLD,
   KC_TRNS,
   KC_TRNS, RGB_HUD, RGB_HUI
   ),

  /* Keymap 2: Qwerty layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L2  |   Y  |   U  |   I  |   O  |   P  |   Å    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
   * |--------+------+------+------+------+------| Win  |           | RAlt |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -_ | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |Mute  | End  |       |ply/ps| next |
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       |vol u |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | Del  |       |vol d |        |      |
   *                                 `--------------------'       `----------------------'
   */
  [QWERTY] = LAYOUT_ergodox
  (
   // left hand
   KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
   KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
   KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
   KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_LGUI,
   NO_CIRC,        KC_GRV,    LALT(KC_LSFT),  KC_LEFT,  KC_RGHT,
   KC_MUTE,        KC_END,
   KC_HOME,
   KC_SPC,         KC_BSPC,      KC_DEL,
   // right hand
   KC_RGHT,        KC_6,   KC_7,  KC_8,   KC_9,   KC_0,       KC_MINS,
   TG(QWERTY),     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,       NO_AA,
   KC_H,           KC_J,   KC_K,  KC_L ,  NO_OSLH,NO_AE,
   KC_RALT,        KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,    KC_RSFT,
   KC_UP,          KC_DOWN,KC_LBRC,KC_RBRC,KC_FN1,
   KC_MPLY,        KC_MNXT,
   KC_VOLU,
   KC_VOLD, KC_LALT, KC_ENT
   )

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};

/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"
#include "keymap_nordic.h"
#include "keymap_swedish.h"

// Layer shorthand
#define _CM 0
#define _FN 1
#define _QT 2

#define SE_ALGR KC_RALT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | +?\    | prev m | next m | PLY/PS |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | F      | P      | G      | J      | L      | U      | Y      | Ö      | Å      | "^~    | '`     | vol up |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | R      | S      | T      | D      | H      | N      | E      | I      | O      | Ä      | '*´    | §½     |vol down|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | K      | M      | ,;     | .:     | -_̣     | RSHIFT | HOME   |  UP    | END    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | <>|    | LGUI   | LALT   | FN     | SPACE  | BSPACE | LALT   | ENTER  | ALTGR  | RGUI   | DEL    | QWERTY | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_CM] = {
     { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,KC_MPRV, KC_MNXT, KC_MPLY  },
     { KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    NO_OSLH, NO_AA,   NO_QUOT, NO_ACUT, KC_VOLU  },
     { KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    NO_AE,   KC_BSLS, KC_GRV,  KC_VOLD  },
     { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_HOME, KC_UP,   KC_END   },
     { KC_NUBS, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_BSPC,  KC_LALT, KC_ENT,  SE_ALGR, KC_RGUI, KC_DEL,  TG(_QT), KC_LEFT, KC_DOWN, KC_RGHT  },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | NUMLK  | P/     | P*     | P-     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    |        |        |        |        | RGB HD | RGB HI | {      | UP     | }      | F11    | P7     | P8     | P9     | P+     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  |        |        | {      | }      | RGB SD | RGB SI | LEFT   | DOWN   | RIGHT  | F12    | P4     | P5     | P6     | P+     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LSHF   |        |        | [      | ]      | RGB VD | RGB VI | [      |  '*´   | ]      | PR SCR | P1     | P2     | P3     | P ENT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | LGUI   | LALT   | FN     | RGB TG | RGB RMD| RGB MD |        | AL GR  | INS    | RESET  | P0     | P0     | P,     | P ENT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NLCK, KC_SLSH, KC_ASTR, KC_MINS  },
  { KC_TAB,  _______, _______, _______, _______, RGB_HUD, RGB_HUI, NO_LCBR, KC_UP,   NO_RCBR, KC_F11,   KC_P7,   KC_P8,   KC_P9,   KC_PLUS  },
  { KC_LCTL, _______, _______, NO_LCBR, NO_RCBR, RGB_SAD, RGB_SAI, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12,   KC_P4,   KC_P5,   KC_P6,   KC_PLUS  },
  { KC_LSFT, _______, _______, NO_LBRC, NO_RBRC, RGB_VAD, RGB_VAI, NO_LBRC, KC_BSLS, NO_RBRC, KC_PSCR,  KC_P1,   KC_P2,   KC_P3,   KC_ENT  },
  { _______, KC_LGUI, KC_LALT, KC_TRNS, RGB_TOG, RGB_RMOD,RGB_MOD, _______, SE_ALGR, KC_INS,  RESET,    KC_P0,   KC_P0,   KC_PDOT, KC_PENT  },
 },

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | BSPACE | LALT   | ENTER  | ALTGR  | RGUI   | SPACE  |        | RALT   | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QT] = {
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,KC_MPRV, KC_MNXT, KC_MPLY  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_AA,   NO_QUOT, NO_ACUT, KC_VOLU  },
  { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, NO_AE,   KC_BSLS, KC_GRV,  KC_VOLD  },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_HOME, KC_UP,   KC_END   },
  { KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  KC_BSPC, KC_LALT, KC_ENT,  SE_ALGR, KC_RGUI, KC_RCTL, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT  },
 },
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

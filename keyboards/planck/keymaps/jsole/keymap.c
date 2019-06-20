/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _MAC,
  _WIN,
  _MOUSE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  MAC = SAFE_RANGE,
  WIN,
  MOUSE,
  // BACKLIT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define KC_INQS RALT(S(KC_SLSH))
#define KC_UPQS S(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Mac
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Sh/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |AppFn |Lower |Space |Space |Raise |//RAl | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_planck_grid(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,KC_UP, RSFT_T(KC_ENT),
    KC_LCTL, KC_LALT, KC_LGUI, KC_LEAD,TT(LOWER),KC_SPC,KC_SPC,TT(RAISE),RALT_T(KC_SLSH), KC_LEFT,KC_DOWN, KC_RGHT
),

/* Win
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Sh/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | RAlt |Lower |Space |Space |Raise |//RAl | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WIN] = LAYOUT_planck_grid(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,KC_UP, RSFT_T(KC_ENT),
    KC_LCTL, KC_LGUI, KC_LALT, KC_RALT,TT(LOWER),KC_SPC,KC_SPC,TT(RAISE),RALT_T(KC_SLSH), KC_LEFT,KC_DOWN, KC_RGHT
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      | Btn1 | M_Up | Btn2 | SclU | Spd0 |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | M_Lt | M_Dn | M_Rt | SclD | Spd1 |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  | Btn3 |  F9  |      | Spd2 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    XXXXXXX,KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,KC_ACL0,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    XXXXXXX,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,KC_ACL1,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
    _______,XXXXXXX,KC_BTN3,XXXXXXX,XXXXXXX,KC_ACL2,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  -   |  =   |  [   |  ]   |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  _   |  +   |  {   |  }   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | PgUp | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_ESC ,KC_EXLM, KC_AT ,KC_HASH, KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN, KC_DEL,
    KC_DEL , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,KC_MINS, KC_EQL,KC_LBRC,KC_RBRC,KC_PIPE,
    _______, KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,KC_PGUP,KC_HOME,KC_PGDN,KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  -   |  =   |  [   |  ]   |  ?   |  +   |   4  |   5  |   6  |  ,   |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  _   |  +   |  {   |  }   |  ¿   |  -   |   1  |   2  |   3  |  .   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  | Home |  =   | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_DEL,
    KC_DEL ,KC_MINS, KC_EQL,KC_LBRC,KC_RBRC,KC_UPQS,KC_PLUS, KC_4  , KC_5  , KC_6  ,KC_COMM,KC_BSLS,
    _______,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_INQS,KC_MINS, KC_1  , KC_2  , KC_3  ,KC_DOT ,_______,
    _______,_______,_______,_______,_______,_______,_______,_______, KC_0  ,KC_HOME, KC_EQL, KC_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|      |      |      |      |      |      |      |PrntSc|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |      |      |      |      |  Mac |  Win |Mouse |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Next | Vol- | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______,  RESET,  DEBUG,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,_______,
    KC_CAPS,_______,_______,_______,_______,  MAC  ,  WIN  , MOUSE ,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_VOLU,_______,
    _______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MNXT,KC_VOLD,KC_MPLY
)

};

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case RSFT_T(KC_ENT):
      return 100;
      case RALT_T(KC_SLSH):
      return 180;
    default:
      return TAPPING_TERM;
  }
}

// #ifdef AUDIO_ENABLE
//   float plover_song[][2]     = SONG(PLOVER_SOUND);
//   float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
// #endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_MAC);
      }
      return false;
      break;
    case WIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WIN);
      }
      return false;
      break;
      case MOUSE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MOUSE);
      }
      return false;
      break;
  }
  return true;
}

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;

// void encoder_update(bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_RAISE)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       #ifdef MOUSEKEY_ENABLE
//         register_code(KC_MS_WH_DOWN);
//         unregister_code(KC_MS_WH_DOWN);
//       #else
//         register_code(KC_PGDN);
//         unregister_code(KC_PGDN);
//       #endif
//     } else {
//       #ifdef MOUSEKEY_ENABLE
//         register_code(KC_MS_WH_UP);
//         unregister_code(KC_MS_WH_UP);
//       #else
//         register_code(KC_PGUP);
//         unregister_code(KC_PGUP);
//       #endif
//     }
//   }
// }

// void dip_update(uint8_t index, bool active) {
//   switch (index) {
//     case 0:
//       if (active) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_song);
//         #endif
//         layer_on(_ADJUST);
//       } else {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_gb_song);
//         #endif
//         layer_off(_ADJUST);
//       }
//       break;
//     case 1:
//       if (active) {
//         muse_mode = true;
//       } else {
//         muse_mode = false;
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//         #endif
//       }
//    }
// }

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // SEQ_ONE_KEY(KC_F) {
    //   // Anything you can do in a macro.
    //   SEND_STRING("QMK is awesome.");
    // }
    // SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTRL("a")SS_LCTRL("c"));
    // }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_G) {
      SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS (KC_R, KC_R) {
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
      tap_random_base64();
    }
    // SEQ_TWO_KEYS(KC_A, KC_S) {
    //   register_code(KC_LGUI);
    //   register_code(KC_S);
    //   unregister_code(KC_S);
    //   unregister_code(KC_LGUI);
    // }
  }
}

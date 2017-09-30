#include "tada68.h"
#include "timer.h"

enum {
  MR_ESC_CAPS = 0,
  MR_NXT_TRACK = 1,
  MR_PRV_TRACK = 2,
  MR_EMO_LENNY = 3,
  MR_EMO_SHRUG = 4
};

// Layers
#define _BL 0
#define _FL 1

// Buttons
#define _______ KC_TRNS
#define ESC_CAPS M(MR_ESC_CAPS)
#define TR_NEXT M(MR_NXT_TRACK)
#define TR_PREV M(MR_PRV_TRACK)
#define TRLENNY M(MR_EMO_LENNY)
#define TRSHRUG M(MR_EMO_SHRUG)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |GEsc| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |ESC/CAP|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  ESC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,          KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL,  KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_FL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |   |   |   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |<- |Dn | ->|   |   |   |   |TRP|TR-|TR+|   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |MUT|VU-|VU+|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  _______, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS ,  \
  _______,_______, KC_UP,_______,_______, _______,_______,_______,_______,_______,_______,_______,_______, _______,KC_HOME, \
  _______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,KC_MPLY,TR_PREV,TR_NEXT,_______,        _______,KC_END, \
  _______,_______,_______,BL_DEC, BL_TOGG,BL_INC, _______,KC_MUTE,KC_VOLD,KC_VOLU,_______,KC_BTN1, KC_MS_U, KC_BTN2, \
  _______,_______,_______,                 _______,               _______,_______,_______,KC_MS_L,KC_MS_D, KC_MS_R),
};

bool is_caps_on = false;

// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case MR_ESC_CAPS:
      // Shift + Caps for Capslock
      if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
        if(is_caps_on) {
          // Turn capslock on
          is_caps_on = false;
          return MACRO( U(CAPS), END );
        } else {
          // Turn capslock off
          is_caps_on = true;
          return MACRO( D(CAPS), END );
        }
      } else {
        if (record->event.pressed) {
          return MACRO( T(ESC), END);
        }
      }
      break;
    case MR_NXT_TRACK:
      // Next track Windows / Mac
      if (record->event.pressed) {
        return MACRO( T(MNXT), T(MFFD), END );
      }
      break;
    case MR_PRV_TRACK:
      // Previous track Windows / Mac
      if (record->event.pressed) {
        return MACRO( T(MPRV), T(MRWD), END );
      }
      break;
  }
  return MACRO_NONE;
}
;

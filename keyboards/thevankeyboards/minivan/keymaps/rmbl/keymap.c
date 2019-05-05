#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layers {
  _QW,
  _L1,
  _L2
};

enum keycodes {
  SPACES
};

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

#define TABL1 LT(_L1, KC_TAB)
#define QUTL1 LT(_L1, KC_QUOT)
#define SLSHL2 LT(_L2, KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT_arrow( /* Qwerty */
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    TABL1  , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, QUTL1,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP  , SLSHL2,
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,  KC_ENT,           KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_L1] = LAYOUT_arrow( /* LAYER 1 */
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL ,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), _______, KC_PGUP, _______,
    _______, _______, _______,                   SPACES,  _______,             _______,    KC_HOME, KC_PGDN, KC_END
  ),
  [_L2] = LAYOUT_arrow( /* LAYER 2 */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, KC_PGUP, _______,
    _______, _______, _______,                   SPACES,  _______,          _______, KC_HOME, KC_PGDN, KC_END
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SPACES:
      // Send 60 spaces to fill up time tracking field
      if (record->event.pressed) {
        SEND_STRING("                                                            ");
      }
      return false;
      break;
  }
  return true;
}


#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   6  |
 * |------+------+------+------+------+------|
 * |BSpace|   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------+------|
 * |Shift |   Y  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------+------|
 * | Ctrl | Alt  |Space |BSpace|Return|Space |
 * `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,       KC_1,    KC_2,     KC_3,   KC_4,    KC_5, _______, _______, _______, _______, _______, _______, \
  KC_TAB,       KC_Q,    KC_W,     KC_E,   KC_R,    KC_6, _______, _______, _______, _______, _______, _______, \
  MO(_RAISE),   KC_A,    KC_S,     KC_D,   KC_F,    KC_G, _______, _______, _______, _______, _______, _______, \
  KC_LSFT,      KC_Y,    KC_X,     KC_C,   KC_V,    KC_B, _______, _______, _______, _______, _______, _______, \
  KC_LCTL,   KC_LALT,  KC_SPC,  KC_BSPC, KC_ENT,  KC_SPC, _______, _______, _______, _______, _______, _______ \
),
 
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------+------|
 * | Del  |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------+------|
 * |      | F11  | F12  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, _______, _______, _______, _______, _______, \
  KC_DEL,    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______, _______, _______, _______, _______, _______, \
  _______,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

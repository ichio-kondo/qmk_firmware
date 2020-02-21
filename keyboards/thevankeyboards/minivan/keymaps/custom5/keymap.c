#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

enum custom_layers {
  _QWERTY,
  _ICHIO,
  _LOWER,
  _RAISE,
  _ARROW
};
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ICHIO,
  IMEON,
  PSSS,
  PPPC
};
#define KC_ENTRO LT(_LOWER,KC_ENT)
#define KC_SPCRI LT(_RAISE, KC_SPC)
#define KC_ECSIC LT(_ICHIO,KC_ESC)
#define KC_ARROW LT(_ARROW,KC_LANG2)
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI ALT_T(IMEON)
#define KC_LOWEI GUI_T(KC_LANG2)
#define KC_ALTKN GUI_T(KC_LANG1)
#define KC_PPPC PPPC
#define KC_PSSS PSSS
#define KC_RSFTD RSFT_T(KC_PIPE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* Qwerty */
    KC_ECSIC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_CTLTB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFTD,
    KC_DEL,KC_GUIEI,KC_ALTKN,                   KC_ENTRO,KC_SPCRI,               KC_ARROW, KC_ESC,  KC_RSFT
  ),
  [_LOWER] = LAYOUT( /* LAYER 1 */
      KC_TILD, KC_EXLM, KC_AT, KC_HASH,   KC_DLR, KC_PERC,KC_CIRC, KC_AMPR,KC_ASTR,KC_LPRN, KC_RPRN, KC_BSPC,
    _______, _______, _______, _______, _______, KC_QUOT,KC_MINS,KC_EQL,KC_TILD, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______,  _______,  _______, _______, KC_DQUO, KC_UNDS,KC_PLUS,KC_SLSH, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_DEL,KC_GUIEI,KC_ALTKN,                   KC_ENTRO,KC_SPCRI,               KC_LOWEI, _______,  KC_RSFT
  ),
  [_RAISE] = LAYOUT( /* LAYER 2 */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    _______,  _______,  _______,  _______, _______, KC_QUOT,KC_MINS,KC_EQL,KC_TILD,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______,  _______,  _______, _______, KC_DQUO, KC_UNDS,KC_PLUS,KC_SLSH, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_DEL,KC_GUIEI,KC_ALTKN,                   KC_ENTRO,KC_SPCRI,               KC_LOWEI, _______,  KC_RSFT
  ),
  [_ICHIO] = LAYOUT( /* LAYER 3 */
    _______, KC_PSSS, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,KC_F7, KC_F8, KC_F9,KC_F10,KC_1,
    _______, KC_F11,KC_F12,KC_F13, _______, _______, _______,  _______,  _______,  _______,  _______,RESET,
    _______, _______, _______,_______, _______, _______, _______, KC__MUTE,KC__VOLDOWN,KC__VOLUP, KC_MPRV,KC_MNXT,
    KC_DEL,KC_GUIEI,KC_ALTKN,                    KC_ENTRO,KC_SPCRI,               KC_LOWEI, _______,  KC_RSFT
  ),
  [_ARROW] = LAYOUT( /* LAYER 3 */
    _______, _______, _______,_______, _______, _______, _______, _______,_______,_______,KC_UP,_______,
    _______, _______,_______,_______, _______, _______, _______,  _______,  _______,  KC_LEFT,KC_RIGHT,_______,
    _______, _______, _______,_______, _______, _______, _______, _______,_______,KC_DOWN, _______,_______,
    _______,_______,_______,                   KC_ENTRO,KC_SPCRI,               _______,_______,_______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case ICHIO:
        if (record->event.pressed) {
          layer_on(_ICHIO);
        } else {
          layer_off(_ICHIO);
        }
        return false;
        break;

    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
   case IMEON:
    if (record->event.pressed) {
          SEND_STRING(SS_LALT("`"));
        } else {
          SEND_STRING ( SS_TAP(X_LANG2));
        }
        return false;
        break;
    case PSSS:
    if (record->event.pressed){
	    SEND_STRING("1qaz2wsx#E");
    }
    break;

    case PPPC:
   if (record->event.pressed){
	    SEND_STRING(SS_LGUI(SS_LSFT("5")));
    }
    break;
    }
  return true;
}
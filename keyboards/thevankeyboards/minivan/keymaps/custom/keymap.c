#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _MOUFN 4

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,
  MOUFN,
  SSRIGHT,
  SSLEFT,
  IMEON,
  MCPS,
  PSSS,
  PPPC,
  SCSC
};
#define KC_ KC_TRNS

#define KC_PPPC PPPC
#define KC_PSSS PSSS
#define KC_IMEON IMEON
#define KC_SSRIGHT LCTL(KC_RIGHT)
#define KC_SSLEFT LCTL(KC_LEFT)
#define KC_AARIGHT LGUI(LSFT(KC_RIGHT))
#define KC_AALEFT LGUI(KC_LEFT)
#define KC_MOUFN MOUFN
#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_ADJUST ADJUST
#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LMOD  RGB_MOD
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIEI GUI_T(KC_LANG1)
#define KC_ALTKN ALT_T(KC_BSPC)
#define KC_RSFTD RSFT_T(KC_DQUO)
#define KC_SPCRI LT(_LOWER, KC_SPC)
#define KC_LOWEB LT(_RAISE,KC_ENT)
#define KC_LOWED LT(_RAISE,KC_DEL)
#define KC_EMOUFN LT(_MOUFN,KC_ESC)
#define KC__VOLUP	KC_VOLU
#define KC__MUTE KC_MUTE
#define KC__VOLDOWN KC_VOLD
#define KC_LALT LALT
#define KC_LOWEI LT(_RAISE,KC_LANG2)
#define KC_PSCR KC_PSCREEN
#define KC_SCSC KC_SCSC


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_EMOUFN,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,   KC_O,  KC_P, KC_BSPC ,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_CTLTB,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G, KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_ENT,\
  //|------+------+------+------+------+------|                |------+-----+------+------+------+------|
       KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,  KC_B,  KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFTD,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                         _______, KC_ALTKN,KC_GUIEI,KC_LOWEB,      KC_SPCRI, KC_LOWEI, KC_ADJUST, _______\
                              //`--------------------'  `--------------------'
  ),
   [_LOWER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_GRV,KC_1, KC_2, KC_3,  KC_4, KC_5,               KC_6,     KC_7,    KC_8,     KC_9,     KC_0,  KC_MINS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_CTLTB, KC_HOME, KC_PGUP ,  KC_LCBR , KC_RCBR, KC_QUOT,    KC_MINS,  KC_EQL, KC_UP,  KC_LCBR, KC_SCLN,KC_PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KC_LSFT, KC_END, KC_PGDOWN, KC_LBRC, KC_RBRC, KC_DQUO,   KC_UNDS, KC_LEFT,  KC_DOWN,KC_RIGHT, KC_RBRC, KC_SLSH,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                          _______,KC_ALTKN,KC_IMEON,KC_BSPC,      KC_SPCRI, KC_LOWEI, KC_ADJUST, _______\
                              //`--------------------'  `--------------------'

  ),
 [_RAISE] = LAYOUT(
  //,-----------------------------------------.                ,-----------------------------------------.
      KC_ESC,  KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,         KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_MINS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_CTLTB, KC_PSCR, _______, KC_LCBR, KC_RCBR , KC_QUOT,  KC_MINS,  KC_EQL, KC_TILD, KC_LCBR, KC_RCBR,KC_PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_LSFT,KC_SSLEFT,KC_SSRIGHT, KC_LBRC, KC_RBRC, KC_DQUO,   KC_UNDS, KC_PLUS, _______, KC_LBRC, KC_RBRC, KC_BSLS,\
  //|------+------+------;+------+------+------+------|  |------+------+------+------+------+------+------|/
                                   _______,KC_ALTKN,KC_GUIEI,KC_LOWED,      KC_SPCRI, KC_LOWEI, KC_ADJUST,_______ \
                              //`--------------------'  `--------------------'
  ),
  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
       KC_RST,KC_F1, KC_F2, KC_F3 , KC_F4, KC_F5,             KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,\
  //|------+-----+------+------+------+------|                |------+------+------+------+------+------|
  KC_LTOG,  KC_LHUI,  KC_LSAI, _______, KC_F12,KC_F13,         KC_VOLU,  KC_MUTE,  KC_HOME, _______,  KC_END, KC_F12,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
  KC_LMOD,  KC_LHUD,  KC_LSAD, _______, KC_F14, KC_LRST,   KC_VOLD, KC_AALEFT,_______,KC_AARIGHT,_______, KC_F13,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   _______,KC_ALTKN,KC_GUIEI,KC_LOWEB,      KC_SPCRI, KC_LOWEI, KC_ADJUST,_______ \
                              //`--------------------'  `--------------------'
  ),

[_MOUFN]= LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    KC_EMOUFN,KC_PSSS,KC_ACL1,KC_ACL2, KC_BTN1, KC_BTN2,    _______, _______,_______,_______,_______, KC_ACL0,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_CTLTB,_______,  _______,  _______,  KC_WH_D, KC_PPPC,               _______,KC_BTN1,KC_MS_U,KC_BTN2, KC_ACL1,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      KC_LSFT, _______,_______,  KC_WH_R, KC_WH_U, KC_WH_L,                    _______,KC_MS_L,KC_MS_D,KC_MS_R, KC_ACL2,_______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   _______,KC_SPC,KC_ENT,KC_BSPC,      KC_SPCRI, KC_LOWEI, KC_ADJUST,_______ \
                              //`--------------------'  `--------------------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 
 switch (keycode) {
     case QWERTY:
      if (record->event.pressed) {
        layer_on(_QWERTY);
      } else {
        layer_off(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case MOUFN:
        if (record->event.pressed) {
          layer_on(_MOUFN);
        } else {
          layer_off(_MOUFN);
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
  case SCSC:
   if (record->event.pressed){
	    SEND_STRING(":");
    }
    break;
  } 
  return true;
}
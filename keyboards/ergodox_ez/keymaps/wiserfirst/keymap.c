#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "vim.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define X_____X KC_TRNS
#define KC_ATM LGUI(LSFT(KC_P))
#define KC_ATP LGUI(LCTL(KC_P))
#define TO_NORM TO(NORMAL_MODE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Insert mode
  *
  * ,----------------------------------------------------.           ,----------------------------------------------------.
  * |    `   |   1  |   2  |   3  |   4  |   5  | INS `  |           |   =    |   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+---------------|           |--------+------+------+------+------+------+--------|
  * |   TAB  |   Q  |   W  |   E  |   R  |   T  | NORMAL |           | SYMBOL |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |   ESC  | MS A |   S  |   D  |   F  |   G  |--------|           |--------|   H  |   J  |   K  |   L  | MS ; |   '    |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |  SHIFT |   Z  |   X  |   C  |   V  |   B  | MOUSE  |           |   +    |   N  |   M  |   ,  |   .  |   /  | SHIFT  |
  * `--------+------+------+------+------+---------------'           `---------------+------+------+------+------+--------'
  *   | LCTL |   ⌥  | CMD  |  [   |   ]  |                                           |   ←  |   ↓  |   ↑  |   →  | RCTL |
  *   `----------------------------------'                                           `----------------------------------'
  *
  *                                      ,-----------------.       ,-----------------.
  *                                      | OPTION |  CMD   |       |  COMMAND |OPTION|
  *                               ,------|--------|--------|       |----------+------+-------.
  *                               | BSPC |        |  HOME  |       |  PG UP   |      | SPACE |
  *                               |      | DELETE |--------|       |----------|ENTER |       |
  *                               |   ⌘  |        |  END   |       |  PG DOWN |      |   ⌘   |
  *                               `------------------------'       `-------------------------'
  */
  [INSERT_MODE] = LAYOUT_ergodox(
    // Left Hand
    KC_GRV , KC_1,           KC_2,    KC_3,    KC_4,   KC_5, LT(SYMB,KC_GRV),
    KC_TAB , KC_Q,           KC_W,    KC_E,    KC_R,   KC_T, NOR_MOD,
    KC_ESC , LT(MOUSE,KC_A), KC_S,    KC_D,    KC_F,   KC_G,
    KC_LSFT, KC_Z,           KC_X,    KC_C,    KC_V,   KC_B, MSE_MOD,
    KC_LCTL, KC_LALT,        KC_LGUI, KC_LBRC, KC_RBRC,

                                                                   KC_LALT, KC_LGUI,
                                                                            KC_HOME,
                                                   GUI_T(KC_BSPC), KC_DEL , KC_END ,

    // Right Hand
                              KC_EQUAL, KC_6, KC_7,    KC_8,    KC_9,   KC_0,              KC_MINS,
                              SYM_MOD , KC_Y, KC_U,    KC_I,    KC_O,   KC_P,              KC_BSLS,
                                        KC_H, KC_J,    KC_K,    KC_L,   LT(MOUSE,KC_SCLN), KC_QUOT,
                              KC_PLUS , KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH,           KC_RSFT,
                                              KC_LEFT, KC_DOWN, KC_UP , KC_RGHT,           KC_RCTL,

    KC_RGUI, KC_RALT,
    KC_PGUP,
    KC_PGDN, KC_ENT, GUI_T(KC_SPC)
  ),

  [SYMB] = LAYOUT_ergodox(
    // Left Hand
    NOR_MOD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_ATM,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, NOR_MOD,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, MSE_MOD,
    _______, _______, _______, KC_LBRC, KC_LCBR,

                                                                RGB_MOD,RGB_RMOD,
                                                                        HSV_86_255_128,
                                                        RGB_VAD,RGB_VAI,HSV_27_255_255,

    // Right Hand
                              KC_ATP , KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                              _______, KC_PGUP, KC_LBRC, KC_LCBR, KC_O,    KC_ASTR, KC_F12,
                                       _______, _______, _______, _______, KC_PLUS, _______,
                              _______, KC_PGDN, KC_RBRC, KC_RCBR, KC_DOT,  KC_BSLS, KC_RSFT,
                                                _______, _______, _______, _______, _______,

    RGB_TOG,RGB_SLD,
    RGB_SAI,
    RGB_SAD,RGB_HUD,RGB_HUI
  ),

  [MOUSE] = LAYOUT_ergodox(
    // Left Hand
    NOR_MOD,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,KC_MS_U,_______,_______,NOR_MOD,
    _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,KC_BTN1,KC_BTN2,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,RESET,
                              SYM_MOD,_______,KC_BTN1,KC_BTN2,KC_BTN3,_______,_______,
                                      KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,KC_MPLY,
                              _______,_______,_______,KC_MNXT,KC_MPRV,_______,_______,
                                              KC_MUTE,KC_VOLD,KC_VOLU,_______,_______,

    _______,_______,
    _______,
    _______,_______,_______
  ),

  /* Normal mode
  *
  * ,----------------------------------------------------.           ,-----------------------------------------------------.
  * |        |      |      |      |      |      |        |           |        |      |      |      |      |       |        |
  * |--------+------+------+------+------+---------------|           |--------+------+------+------+------+-------+--------|
  * |  TAB   |      | WORD |  END |      |      | INSERT |           | SYMBOL | YANK | UNDO |INSERT| OPEN |  PUT  |        |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+-------+--------|
  * |    ⎋   |APPEND|      |  DEL |      |      |--------|           |--------|  ←   |  ↓   |  ↑   |  →   | MOUSE |    ⎋   |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+-------+--------|
  * | SHIFT  |      |      |      |VISUAL| BACK | MOUSE  |           |        |      |      |      |      |       | SHIFT  |
  * `--------+------+------+------+------+---------------'           `---------------+------+------+------+-------+--------'
  *   | CTL  |OPTION| CMD  |      |      |                                           |      |      |      |       | PAIR |
  *   `----------------------------------'                                           `-----------------------------------'
  *                                      ,-----------------.       ,-----------------.
  *                                      | OPTION |  CMD   |       |  COMMAND |OPTION|
  *                               ,------|--------|--------|       |----------+------+-------.
  *                               | BSPC |        |  HOME  |       |  PG UP   |      | SPACE |
  *                               |      | DELETE |--------|       |----------|ENTER |       |
  *                               |   ⌘  |        |  END   |       |  PG DOWN |      |   ⌘   |
  *                               `------------------------'       `-------------------------'
  */
  [NORMAL_MODE] = LAYOUT_ergodox(
    // Layer 2 Left Hand
    X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
    KC_TAB ,X_____X,VIM_W,  VIM_E  ,X_____X,X_____X,X_____X,
    X_____X,VIM_A  ,VIM_S  ,VIM_D  ,X_____X,X_____X,
    KC_LSFT,X_____X,VIM_X  ,VIM_C  ,VIM_V  ,VIM_B  ,MSE_MOD,
    KC_LCTL,KC_LALT,KC_LGUI,X_____X,X_____X,

                                                             KC_LALT,KC_LGUI,
                                                                     KC_HOME,
                                            GUI_T(KC_BSPC),  KC_DEL ,KC_END ,


    // Layer 2 Right Hand
                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,
                              SYM_MOD,VIM_Y  ,VIM_U  ,VIM_I  ,VIM_O  ,VIM_P  ,X_____X,
                                      VIM_H  ,VIM_J  ,VIM_K  ,VIM_L  ,MSE_MOD,X_____X,
                              X_____X,X_____X,X_____X,X_____X,X_____X,X_____X,KC_RSFT,
                                              X_____X,X_____X,X_____X,KC_RALT,KC_RCTL,

    KC_RGUI, KC_RALT,
    KC_PGUP,
    KC_PGDN, KC_ENT, GUI_T(KC_SPC)
),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 0:
      if (record->event.pressed) { SEND_STRING (VERSION_STRING); }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) |
                 (keyboard_report->mods & MOD_BIT(KC_RSFT));

  switch (keycode) {
    case VIM_A:
      if (record->event.pressed) { SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND(); }
      return false;

    case VIM_B:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: VIM_BACK(); break;
          case VIM_C: VIM_CHANGE_BACK(); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
      }
      return false;

    case VIM_C:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_D:
      if (record->event.pressed) {
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_DELETE_LINE() : VIM_LEADER(VIM_D); break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
      }
      return false;

    case VIM_E:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_END(); break;
          case VIM_C: VIM_CHANGE_END(); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
        }
      }
      return false;

    case VIM_H:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_LEFT(); break;
          case VIM_C: VIM_CHANGE_LEFT(); break;
          case VIM_D: VIM_DELETE_LEFT(); break;
          case VIM_V: VIM_VISUAL_LEFT(); break;
        }
      }
      return false;

    case VIM_I:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: layer_move(INSERT_MODE); break;
          case VIM_C: VIM_LEADER(VIM_CI); break;
          case VIM_D: VIM_LEADER(VIM_DI); break;
          case VIM_V: VIM_LEADER(VIM_VI); break;
        }
      }
      return false;

    case VIM_J:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break;
          case VIM_C: VIM_CHANGE_DOWN(); break;
          case VIM_D: VIM_DELETE_DOWN(); break;
          case VIM_V: VIM_VISUAL_DOWN(); break;
        }
      }
      return false;

    case VIM_K:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_UP(); break;
          case VIM_C: VIM_CHANGE_UP(); break;
          case VIM_D: VIM_DELETE_UP(); break;
          case VIM_V: VIM_VISUAL_UP(); break;
        }
      }
      return false;

    case VIM_L:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_RIGHT(); break;
          case VIM_C: VIM_CHANGE_RIGHT(); break;
          case VIM_D: VIM_DELETE_RIGHT(); break;
          case VIM_V: VIM_VISUAL_RIGHT(); break;
        }
      }
      return false;

    case VIM_O:
      if (record->event.pressed) { SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN(); }
      return false;

    case VIM_P:
      if (record->event.pressed) { SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT(); }
      return false;

    case VIM_S:
      if (record->event.pressed) { SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE(); }
      return false;

    case VIM_U:
      if (record->event.pressed) { VIM_UNDO(); }
      return false;

    case VIM_V:
      if (record->event.pressed) { VIM_LEADER(VIM_V); }
      return false;

    case VIM_W:
      if (record->event.pressed) {
        switch (VIM_QUEUE) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
          case VIM_D: VIM_DELETE_WORD(); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
        }
      }
      return false;

    case VIM_X:
      if (record->event.pressed) { VIM_CUT(); }
      return false;

    case VIM_Y:
      if (record->event.pressed) { SHIFTED ? VIM_YANK_LINE() : VIM_YANK(); }
      return false;

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) { eeconfig_init(); }
      return false;

    case VRSN:
      if (record->event.pressed) { SEND_STRING(VERSION_STRING); }
      return false;

    case RGB_SLD:
      if (record->event.pressed) { rgblight_mode(1); }
      return false;

    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;

    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;

    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
  }

  // End by clearing the queue unless keycode is a
  // if ((record->event.pressed) &&
  //     (keycode != VIM_I ||
  //     keycode != VIM_C ||
  //     keycode != VIM_D ||
  //     keycode != VIM_V)) {
  //   VIM_LEADER(KC_NO);
  // }

  return true;
};

void matrix_init_user(void) {
  debug_enable = true;
  VIM_LEADER(KC_NO);
};

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }
};

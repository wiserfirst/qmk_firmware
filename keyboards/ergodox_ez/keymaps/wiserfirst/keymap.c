#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "vim.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define X_____X KC_TRNS
#define ___X___ KC_NO

/* GUI === CMD === WIN and ALT === OPT */
#define L_PANE LGUI(LALT(KC_LEFT))
#define R_PANE LGUI(LALT(KC_RIGHT))
#define OPT_L LALT(KC_LEFT)
#define OPT_R LALT(KC_RIGHT)
#define CMD_L LCMD(KC_LEFT)
#define CMD_R LCMD(KC_RIGHT)

#define SW_INPT LCTL(KC_SPACE)

#define TO_NORM TO(NORMAL_MODE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Insert mode
  *
  * ,----------------------------------------------------.           ,----------------------------------------------------.
  * |    `   |   1  |   2  |   3  |   4  |   5  | SYMB ` |           |   =    |   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+---------------|           |--------+------+------+------+------+------+--------|
  * |   TAB  |   Q  |   W  |   E  |   R  |   T  | NORMAL |           | MOUSE  |   Y  |   U  |   I  |   O  |   P  |   \    |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |   ESC  |SYM A |   S  |   D  |   F  |   G  |--------|           |--------|   H  |   J  |   K  |   L  | MS ; |   '    |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |  SHIFT |   Z  |   X  |   C  |   V  |   B  | SYMBOL |           | SYMBOL |   N  |   M  |   ,  |   .  |   /  | SHIFT  |
  * `--------+------+------+------+------+---------------'           `---------------+------+------+------+------+--------'
  *   | LCTL |   ⌥  | CMD  | CMD L| CMD R|                                           | L PN | R PN | OPT L| OPT R| Cmd~ |
  *   `----------------------------------'                                           `----------------------------------'
  *
  *                                      ,-----------------.       ,-----------------.
  *                                      |   ←    |   →    |       |   ↓     |  ↑    |
  *                               ,------|--------|--------|       |---------+-------+-------.
  *                               |      |        |  HOME  |       | PG UP   |       |       |
  *                               | BSPC | DELETE |--------|       |---------| ENTER | SPACE |
  *                               |      |        |  END   |       | PG DOWN |       |       |
  *                               `------------------------'       `------------------------'
  */
  [INSERT_MODE] = LAYOUT_ergodox(
    // Left Hand
    KC_GRV , KC_1,          KC_2,    KC_3,  KC_4,  KC_5, LT(SYMB,KC_GRV),
    KC_TAB , KC_Q,          KC_W,    KC_E,  KC_R,  KC_T, NOR_MOD,
    KC_ESC , LT(SYMB,KC_A), KC_S,    KC_D,  KC_F,  KC_G,
    KC_LSFT, KC_Z,          KC_X,    KC_C,  KC_V,  KC_B, SYM_MOD,
    KC_LCTL, KC_LALT,       KC_LGUI, CMD_L, CMD_R,

                                                                   KC_LEFT, KC_RGHT,
                                                                            KC_HOME,
                                                          KC_BSPC, KC_DEL , KC_END ,

    // Right Hand
                              KC_EQUAL, KC_6, KC_7,   KC_8,    KC_9,   KC_0,              KC_MINS,
                              MSE_MOD , KC_Y, KC_U,   KC_I,    KC_O,   KC_P,              KC_BSLS,
                                        KC_H, KC_J,   KC_K,    KC_L,   LT(MOUSE,KC_SCLN), KC_QUOT,
                              SYM_MOD , KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,           KC_RSFT,
                                              L_PANE, R_PANE,  OPT_L,  OPT_R,             LGUI(KC_TILD),

    KC_DOWN, KC_UP,
    KC_PGUP,
    KC_PGDN, KC_ENT, KC_SPC
  ),

  /* Symbol mode
  *
  * ,----------------------------------------------------.           ,----------------------------------------------------.
  * | NORMAL |  F1  |  F2  |  F3  |  F4  |  F5  |  [x]   |           |  TROLL |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
  * |--------+------+------+------+------+---------------|           |--------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      | NORMAL |           |        | PG U |   [  |   {  | <%=  |COFFEE|  F12   |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |--------|           |--------|   ←  |   ↓  |   ↑  |  →   | BLUE |  +1    |
  * |--------+------+------+------+------+------|        |           |        |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |  [x]   |           |  [x]   | PG D |   ]  |   }  |  %>  |   /  | SHIFT  |
  * `--------+------+------+------+------+---------------'           `---------------+------+------+------+------+--------'
  *   |      |   ⌥  | CMD  |      |      |                                           |LAUGH |SMILE | WINK |   →  | SAD  |
  *   `----------------------------------'                                           `----------------------------------'
  *
  *                                    ,-------------------.       ,-------------------.
  *                                    | LED MOD | LED RMD |       | LED ON  | LED SLD |
  *                             ,------|---------|---------|       |---------+---------+-------.
  *                             | LED  |   LED   | LED GRN |       | LED SAI |   LED   |  LED  |
  *                             | VAL  |   VAL   |---------|       |---------|   HUE   |  HUE  |
  *                             | DEC  |   INC   | LED RED |       | LED SAD |   DEC   |  INC  |
  *                             `--------------------------'       `---------------------------'
  */
  [SYMB] = LAYOUT_ergodox(
    // Left Hand
    NOR_MOD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ___X___,
    _______, KC_EXLM, KC_AT,   U_ARROW, KC_RCBR, KC_PIPE, NOR_MOD,
    _______, ___X___, L_ARROW, D_ARROW, R_ARROW, KC_GRV,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, ___X___,
    _______, _______, _______, KC_LBRC, KC_LCBR,

                                                                 RGB_MOD, RGB_RMOD,
                                                                          LED_GRN,
                                                        RGB_VAD, RGB_VAI, LED_RED,

    // Right Hand
                              TROLL,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                              _______, KC_PGUP, KC_LBRC, KC_LCBR, L_ERB,   COFFEE,  KC_F12,
                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LED_BLU, PLUS_ONE,
                              ___X___, KC_PGDN, KC_RBRC, KC_RCBR, R_ERB,   KC_BSLS, _______,
                                                LAUGH,   SMILE,   WINK,    CLAP,    SAD,

    RGB_TOG, RGB_SLD,
    RGB_SAI,
    RGB_SAD, RGB_HUD, RGB_HUI
  ),

  [MOUSE] = LAYOUT_ergodox(
    // Left Hand
    NOR_MOD,___X___,___X___,___X___,___X___,___X___,___X___,
    ___X___,___X___,___X___,KC_MS_U,___X___,___X___,NOR_MOD,
    ___X___,___X___,KC_MS_L,KC_MS_D,KC_MS_R,___X___,
    ___X___,___X___,___X___,___X___,___X___,___X___,SYM_MOD,
    ___X___,___X___,___X___,KC_BTN1,KC_BTN2,

                                                                SW_INPT,_______,
                                                                        _______,
                                                        KC_BTN1,KC_BTN2,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,RESET,
                              ___X___,_______,_______,_______,_______,_______,_______,
                                      KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,KC_MPLY,
                              SYM_MOD,_______,_______,KC_MNXT,KC_MPRV,_______,_______,
                                              KC_MUTE,KC_VOLD,KC_VOLU,_______,_______,

    _______,_______,
    _______,
    _______,KC_WBAK,KC_WFWD
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

  if (record->event.pressed) {
    switch (keycode) {
      case VIM_A:
        SHIFTED ? VIM_APPEND_LINE() : VIM_APPEND();
        return false;

      case VIM_B:
        switch(VIM_QUEUE) {
          case KC_NO: VIM_BACK(); break;
          case VIM_C: VIM_CHANGE_BACK(); break;
          case VIM_D: VIM_DELETE_BACK(); break;
          case VIM_V: VIM_VISUAL_BACK(); break;
        }
        return false;

      case VIM_C:
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_CHANGE_LINE() : VIM_LEADER(VIM_C); break;
          case VIM_C: VIM_CHANGE_WHOLE_LINE(); break;
        }
        return false;

      case VIM_D:
        switch(VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_DELETE_LINE() : VIM_LEADER(VIM_D); break;
          case VIM_D: VIM_DELETE_WHOLE_LINE(); break;
        }
        return false;

      case VIM_E:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_END(); break;
          case VIM_C: VIM_CHANGE_END(); break;
          case VIM_D: VIM_DELETE_END(); break;
          case VIM_V: VIM_VISUAL_END(); break;
        }
        return false;

      case VIM_H:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_LEFT(); break;
          case VIM_C: VIM_CHANGE_LEFT(); break;
          case VIM_D: VIM_DELETE_LEFT(); break;
          case VIM_V: VIM_VISUAL_LEFT(); break;
        }
        return false;

      case VIM_I:
        switch (VIM_QUEUE) {
          case KC_NO: layer_move(INSERT_MODE); break;
          case VIM_C: VIM_LEADER(VIM_CI); break;
          case VIM_D: VIM_LEADER(VIM_DI); break;
          case VIM_V: VIM_LEADER(VIM_VI); break;
        }
        return false;

      case VIM_J:
        switch (VIM_QUEUE) {
          case KC_NO: SHIFTED ? VIM_JOIN() : VIM_DOWN(); break;
          case VIM_C: VIM_CHANGE_DOWN(); break;
          case VIM_D: VIM_DELETE_DOWN(); break;
          case VIM_V: VIM_VISUAL_DOWN(); break;
        }
        return false;

      case VIM_K:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_UP(); break;
          case VIM_C: VIM_CHANGE_UP(); break;
          case VIM_D: VIM_DELETE_UP(); break;
          case VIM_V: VIM_VISUAL_UP(); break;
        }
        return false;

      case VIM_L:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_RIGHT(); break;
          case VIM_C: VIM_CHANGE_RIGHT(); break;
          case VIM_D: VIM_DELETE_RIGHT(); break;
          case VIM_V: VIM_VISUAL_RIGHT(); break;
        }
        return false;

      case VIM_O:
        SHIFTED ? VIM_OPEN_ABOVE() : VIM_OPEN();
        return false;

      case VIM_P:
        SHIFTED ? VIM_PUT_BEFORE() : VIM_PUT();
        return false;

      case VIM_S:
        SHIFTED ? VIM_CHANGE_WHOLE_LINE() : VIM_SUBSTITUTE();
        return false;

      case VIM_U:
        VIM_UNDO();
        return false;

      case VIM_V:
        VIM_LEADER(VIM_V);
        return false;

      case VIM_W:
        switch (VIM_QUEUE) {
          case KC_NO: VIM_WORD(); break;
          case VIM_C: VIM_CHANGE_WORD(); break;
          case VIM_CI: VIM_CHANGE_INNER_WORD(); break;
          case VIM_D: VIM_DELETE_WORD(); break;
          case VIM_DI: VIM_DELETE_INNER_WORD(); break;
          case VIM_V: VIM_VISUAL_WORD(); break;
          case VIM_VI: VIM_VISUAL_INNER_WORD(); break;
        }
        return false;

      case VIM_X:
        VIM_CUT();
        return false;

      case VIM_Y:
        SHIFTED ? VIM_YANK_LINE() : VIM_YANK();
        return false;

        // dynamically generate these.
      case EPRM:
        eeconfig_init();
        return false;

      case VRSN:
        SEND_STRING(VERSION_STRING);
        return false;

      case RGB_SLD:
        rgblight_mode(1);
        return false;

      case LED_BLU:
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
        return false;

      case LED_GRN:
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
        return false;

      case LED_RED:
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
        return false;

      case CLAP:
        SEND_STRING(":clap:");
        return false;

      case COFFEE:
        SEND_STRING(":coffee:");
        return false;

      case D_ARROW:
        SEND_STRING(":arrow_down:");
        return false;

      case LAUGH:
        SEND_STRING(":joy:");
        return false;

      case L_ARROW:
        SEND_STRING(":arrow_left:");
        return false;

      case L_ERB:
        SEND_STRING("<%=");
        return false;

      case MINUS_ONE:
        SEND_STRING(":-1:");
        return false;

      case NEUTRAL:
        SEND_STRING(":neutral:");
        return false;

      case NOT_EQUALS:
        SEND_STRING("!=");
        return false;

      case PLUS_ONE:
        SEND_STRING(":+1:");
        return false;

      case R_ARROW:
        SEND_STRING(":arrow_right:");
        return false;

      case R_ERB:
        SEND_STRING("%>");
        return false;

      case SAD:
        SEND_STRING(":disappointed:");
        return false;

      case SMILE:
        SEND_STRING(":smile:");
        return false;

      case TROLL:
        SEND_STRING(":trollface:");
        return false;

      case U_ARROW:
        SEND_STRING(":arrow_up:");
        return false;

      case WINK:
        SEND_STRING(":wink:");
        return false;
    }
  }

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

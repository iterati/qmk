// Copyright 2022 Viatly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v4 -km default
qmk flash -kb avalanche/v4 -km default
*/

#include QMK_KEYBOARD_H

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {200, 50, 10};

/* ************** *
      Defines
 * ************** */
enum layer_names {
  _COLEMAK_DH = 0,
  _QWERTY,
  _GAMING,
  _MOUSE,
  _NAV,
  _ADJUST,
  _SYM,
  _NUM,
  _FN,
};

enum my_keycodes {
  TOG_LO = SAFE_RANGE,
  TOG_OS,
  TOG_GM,
  MY_COPY,
  MY_PSTE,
  MY_CUT,
  MY_REDO,
  MY_UNDO,
};

/* enum custom_keycodes {}; */
#define LMO_TAB LT(_MOUSE, KC_TAB)
#define LNA_SPC LT(_NAV, KC_SPC)
#define LAD_ESC LT(_ADJUST, KC_ESC)
#define LSY_ENT LT(_SYM, KC_ENT)
#define LNU_SPC LT(_NUM, KC_SPC)
#define LFN_BSP LT(_FN, KC_BSPC)

// qwerty homerow
#define A_LGUI LGUI_T(KC_A)
#define S_LALT LALT_T(KC_S)
#define D_LCTL LCTL_T(KC_D)
#define F_LSFT LSFT_T(KC_F)
#define J_LSFT LSFT_T(KC_J)
#define K_LCTL LCTL_T(KC_K)
#define L_LALT LALT_T(KC_L)
#define SC_LGUI LGUI_T(KC_SCLN)

// colemak homerow
#define A_LGUI LGUI_T(KC_A)
#define R_LALT LALT_T(KC_R)
#define S_LCTL LCTL_T(KC_S)
#define T_LSFT LSFT_T(KC_T)
#define N_LSFT LSFT_T(KC_N)
#define E_LCTL LCTL_T(KC_E)
#define I_LALT LALT_T(KC_I)
#define O_LGUI LGUI_T(KC_O)

/* ************** *
       Layout
 * ************** */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* 0 - base layer */
   [_COLEMAK_DH] = LAYOUT(
                  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
         KC_NO,   KC_CAPS, A_LGUI,  R_LALT,  S_LCTL,  T_LSFT,  KC_G,                                        KC_M,    N_LSFT,  E_LCTL,  I_LALT,  O_LGUI,  KC_ENT,  KC_NO,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                             KC_MUTE, LAD_ESC, LNA_SPC, LMO_TAB, KC_LPRN, KC_RPRN, LSY_ENT, LNU_SPC, LFN_BSP, KC_ESC),
   /* 1 - base layer */
   [_QWERTY] = LAYOUT(
                  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
         KC_NO,   KC_CAPS, A_LGUI,  S_LALT,  D_LCTL,  F_LSFT,  KC_G,                                        KC_H,    J_LSFT,  K_LCTL,  L_LALT,  SC_LGUI, KC_ENT,  KC_NO,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                             KC_MUTE, LAD_ESC, LNA_SPC, LMO_TAB, KC_LPRN, KC_RPRN, LSY_ENT, LNU_SPC, LFN_BSP, KC_ESC),

   /* 2 - gaming layer */
   [_GAMING] = LAYOUT(
                  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
         KC_NO,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,  KC_NO,
                  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR, TOG_GM,  TOG_GM,  KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                             KC_MUTE, KC_ESC,  KC_SPC,  KC_TAB,  KC_LPRN, KC_RPRN, KC_ENT,  KC_SPC,  LFN_BSP, KC_ESC),

   /* 3 - right hand */
   [_MOUSE] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_WH_D, KC_MS_U, KC_WH_U, KC_WREF, KC_NO,
         KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                       KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_WBAK, KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN2, KC_BTN1, KC_BTN3, KC_TRNS),

   /* 4 - right hand */
   [_NAV] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_WREF,                                     MY_REDO, MY_CUT,  MY_COPY, MY_PSTE, MY_UNDO, KC_NO,
         KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_NO,
                                             KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,  KC_SPC,  KC_BSPC, KC_TRNS),

   /* 5 - right hand */
   [_ADJUST] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,
         KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                       KC_BRIU, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_SPI, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MSTP, KC_MPLY, KC_MUTE, KC_TRNS),

   /* 6 - left hand */
   [_SYM] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,
         KC_NO,   KC_NO,   KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                     KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,   KC_NO,
                  KC_NO,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_QUOT, KC_RPRN, KC_UNDS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS),

   /* 7 - left hand */
   [_NUM] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,
         KC_NO,   KC_NO,   KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                                      KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,   KC_NO,
                  KC_NO,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_DOT,  KC_0,    KC_MINS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS),

   /* 8  - left hand */
   [_FN] = LAYOUT(
                  KC_NO,   TOG_OS,  TOG_LO,  TOG_GM,  KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,
         KC_NO,   KC_NO,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                                     KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,   KC_NO,
                  KC_NO,   KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_APP,  KC_SPC,  KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS),
};


/* ************** *
    Custom Keys
 * ************** */
bool is_qwerty = false;
bool is_gaming = false;
bool is_mac = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TOG_LO:
      if (record->event.pressed) {
        is_qwerty = !is_qwerty;
        if (is_qwerty) {
          default_layer_set(1UL << _QWERTY);
        } else {
          default_layer_set(1UL << _COLEMAK_DH);
        }
      }
      return false;
    case TOG_OS:
      if (record->event.pressed) {
        is_mac = !is_mac;
      }
      return false;
    case TOG_GM:
      if (record->event.pressed) {
        is_gaming = !is_gaming;
        if (is_gaming) {
          default_layer_set(1UL << _GAMING);
        } else {
          if (is_qwerty) {
            default_layer_set(1UL << _QWERTY);
          } else {
            default_layer_set(1UL << _COLEMAK_DH);
          }
        }
      }
      return false;
    case MY_COPY:
      if (record->event.pressed) {
        if (is_mac) SEND_STRING(SS_LGUI("c"));
        else SEND_STRING(SS_LCTL("c"));
      }
      return false;
    case MY_CUT:
      if (record->event.pressed) {
        if (is_mac) SEND_STRING(SS_LGUI("x"));
        else SEND_STRING(SS_LCTL("x"));
      }
      return false;
    case MY_PSTE:
      if (record->event.pressed) {
        if (is_mac) SEND_STRING(SS_LGUI("v"));
        else SEND_STRING(SS_LCTL("v"));
      }
      return false;
    case MY_REDO:
      if (record->event.pressed) {
        if (is_mac) SEND_STRING(SS_LGUI("y"));
        else SEND_STRING(SS_LCTL("y"));
      }
      return false;
    case MY_UNDO:
      if (record->event.pressed) {
        if (is_mac) SEND_STRING(SS_LGUI("z"));
        else SEND_STRING(SS_LCTL("z"));
      }
      return false;
    default:
      return true;
  }
}

/* ************** *
    OLED Screen
 * ************** */
static const char PROGMEM logo_header[] = {
  0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
  0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
  0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x00
};

static const char PROGMEM logo_slave[] = {
  0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09,
  0x1a, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1b,
  0x1a, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1b,
  0x17, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x19,
  0x00
};

static const char PROGMEM logo_master_t[] = {
  0x01, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x02, 0x03, 0x04,
  0x00
};

static const char PROGMEM logo_master_b[] = {
  0x11, 0x12, 0x13, 0x12, 0x13, 0x12, 0x13, 0x12, 0x13, 0x12, 0x13, 0x12, 0x13, 0x12, 0x13, 0x14,
  0x00
};

static const char PROGMEM logo_os_1[][4] = {
  {0x05, 0xa0, 0xa1, 0},
  {0x05, 0xa4, 0xa5, 0}
};

static const char PROGMEM logo_os_2[][4] = {
  {0x15, 0xa2, 0xa3, 0},
  {0x15, 0xa6, 0xa7, 0}
};

static const char PROGMEM logo_lo_1[][3] = {
  {0xa8, 0xa9, 0},
  {0xac, 0xad, 0}
};

static const char PROGMEM logo_lo_2[][3] = {
  {0xaa, 0xab, 0},
  {0xae, 0xaf, 0}
};

static const char PROGMEM logo_la_1[][3] = {
  {0x80, 0x81, 0}, // alpha
  {0x82, 0x83, 0}, // gaming
  {0x84, 0x85, 0}, // mouse
  {0x86, 0x87, 0}, // navigation
  {0x88, 0x89, 0}, // adjust
  {0x8a, 0x8b, 0}, // symbol
  {0x8c, 0x8d, 0}, // number
  {0x8e, 0x8f, 0}, // function
};

static const char PROGMEM logo_la_2[][3] = {
  {0x90, 0x91, 0}, // alpha
  {0x92, 0x93, 0}, // gaming
  {0x94, 0x95, 0}, // mouse
  {0x96, 0x97, 0}, // navigation
  {0x98, 0x99, 0}, // adjust
  {0x9a, 0x9b, 0}, // symbol
  {0x9c, 0x9d, 0}, // number
  {0x9e, 0x9f, 0}, // function
};

static const char PROGMEM logo_mo_sft_1[][3] = {
  {0x60, 0x61, 0},
  {0x62, 0x63, 0}
};

static const char PROGMEM logo_mo_sft_2[][3] = {
  {0x70, 0x71, 0},
  {0x72, 0x73, 0}
};

static const char PROGMEM logo_mo_ctl_1[][3] = {
  {0x64, 0x65, 0},
  {0x66, 0x67, 0}
};

static const char PROGMEM logo_mo_ctl_2[][3] = {
  {0x74, 0x75, 0},
  {0x76, 0x77, 0}
};

static const char PROGMEM logo_mo_alt_1[][3] = {
  {0x68, 0x69, 0},
  {0x6a, 0x6b, 0}
};

static const char PROGMEM logo_mo_alt_2[][3] = {
  {0x78, 0x79, 0},
  {0x7a, 0x7b, 0}
};

static const char PROGMEM logo_mo_gui_1[][4] = {
  {0x6c, 0x6d, 0x06, 0},
  {0x6e, 0x6f, 0x06, 0}
};

static const char PROGMEM logo_mo_gui_2[][4] = {
  {0x7c, 0x7d, 0x16, 0},
  {0x7e, 0x7f, 0x16, 0}
};

bool oled_task_user(void) {
  oled_write_P(logo_header, false);
  if (is_keyboard_master()) {
    const uint8_t mod = get_mods();
    uint8_t lay;
    switch (get_highest_layer(layer_state)) {
      case _MOUSE:
        lay = 2;
        break;
      case _NAV:
        lay = 3;
        break;
      case _ADJUST:
        lay = 4;
        break;
      case _SYM:
        lay = 5;
        break;
      case _NUM:
        lay = 6;
        break;
      case _FN:
        lay = 7;
        break;
      default:
        lay = 0;
    };
    if (is_gaming) lay = 1;

    oled_write_P(logo_master_t, false);
    oled_write_P(logo_os_1[(is_mac) ? 0 : 1], false);
    oled_write_P(logo_lo_1[(is_qwerty) ? 0 : 1], false);
    oled_write_P(logo_la_1[lay], false);
    oled_write_P(logo_mo_sft_1[(mod & MOD_MASK_SHIFT) ? 1 : 0], false);
    oled_write_P(logo_mo_ctl_1[(mod & MOD_MASK_CTRL) ? 1 : 0], false);
    oled_write_P(logo_mo_alt_1[(mod & MOD_MASK_ALT) ? 1 : 0], false);
    oled_write_P(logo_mo_gui_1[(mod & MOD_MASK_GUI) ? 1 : 0], false);
    oled_write_P(logo_os_2[(is_mac) ? 0 : 1], false);
    oled_write_P(logo_lo_2[(is_qwerty) ? 0 : 1], false);
    oled_write_P(logo_la_2[lay], false);
    oled_write_P(logo_mo_sft_2[(mod & MOD_MASK_SHIFT) ? 1 : 0], false);
    oled_write_P(logo_mo_ctl_2[(mod & MOD_MASK_CTRL) ? 1 : 0], false);
    oled_write_P(logo_mo_alt_2[(mod & MOD_MASK_ALT) ? 1 : 0], false);
    oled_write_P(logo_mo_gui_2[(mod & MOD_MASK_GUI) ? 1 : 0], false);
    oled_write_P(logo_master_b, false);
  } else {
    oled_write_P(logo_slave, false);
  }

  return false;
}

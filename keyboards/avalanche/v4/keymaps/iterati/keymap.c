// Copyright 2022 Viatly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v4 -km default
qmk flash -kb avalanche/v4 -km default
*/

#include QMK_KEYBOARD_H

/* ************** *
      Defines
 * ************** */
enum layer_names {
  _QWERTY = 0,
  _COLEMAK_DH,
  _MOUSE,
  _NAV,
  _ADJUST,
  _SYM,
  _NUM,
  _FN
};

enum my_keycodes {
  TOG_LO = SAFE_RANGE,
  TOG_OS,
  MY_COPY,
  MY_PSTE,
  MY_CUT,
  MY_REDO,
  MY_UNDO,
};

/* enum custom_keycodes {}; */
#define LMO_TAB LT(2,KC_TAB)
#define LNA_SPC LT(3,KC_SPC)
#define LAD_ESC LT(4,KC_ESC)
#define LSY_ENT LT(5,KC_ENT)
#define LNU_SPC LT(6,KC_SPC)
#define LFN_BSP LT(7,KC_BSPC)

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
   [_QWERTY] = LAYOUT(
                  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
         KC_NO,   KC_CAPS, A_LGUI,  S_LALT,  D_LCTL,  F_LSFT,  KC_G,                                        KC_H,    J_LSFT,  K_LCTL,  L_LALT,  SC_LGUI, KC_ENT,  KC_NO,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                             KC_MUTE, LAD_ESC, LNA_SPC, LMO_TAB, KC_LPRN, KC_RPRN, LSY_ENT, LNU_SPC, LFN_BSP, KC_ESC),

   /* 1 - base layer */
   [_COLEMAK_DH] = LAYOUT(
                  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT,
         KC_NO,   KC_CAPS, A_LGUI,  R_LALT,  S_LCTL,  T_LSFT,  KC_G,                                        KC_M,    N_LSFT,  E_LCTL,  I_LALT,  O_LGUI,  KC_ENT,  KC_NO,
                  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                             KC_MUTE, LAD_ESC, LNA_SPC, LMO_TAB, KC_LPRN, KC_RPRN, LSY_ENT, LNU_SPC, LFN_BSP, KC_ESC),

   /* 2 - right hand */
   [_MOUSE] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_WREF,                                     MY_REDO, MY_CUT,  MY_COPY, MY_PSTE, MY_UNDO, KC_NO,
         KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_WSCH,                                     KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_U, KC_WBAK, KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WSTP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_WFWD, KC_NO,
                                             KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN2, KC_BTN1, KC_BTN3, KC_TRNS),

   /* 3 - right hand */
   [_NAV] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_WREF,                                     MY_REDO, MY_CUT,  MY_COPY, MY_PSTE, MY_UNDO, KC_NO,
         KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_NO,
                                             KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,  KC_SPC,  KC_BSPC, KC_TRNS),

   /* 4 - right hand */
   [_ADJUST] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO,
         KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                                       KC_BRIU, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   KC_NO,
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_BRID, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO,
                                             KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MSTP, KC_MPLY, KC_MUTE, KC_TRNS),

   /* 5 - left hand */
   [_SYM] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,
         KC_NO,   KC_NO,   KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                     KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,   KC_NO,
                  KC_NO,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_QUOT, KC_RPRN, KC_UNDS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS),

   /* 6 - left hand */
   [_NUM] = LAYOUT(
                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,
         KC_NO,   KC_NO,   KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                                      KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,   KC_NO,
                  KC_NO,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_DOT,  KC_0,    KC_MINS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS),

   /* 7  - left hand */
   [_FN] = LAYOUT(
                  KC_NO,   TOG_OS,  TOG_LO,  KC_NO,   KC_NO,   KC_NO,                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, KC_NO,
         KC_NO,   KC_NO,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,                                     KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,   KC_NO,
                  KC_NO,   KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_TRNS, KC_APP,  KC_SPC,  KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS)
};


/* ************** *
    Custom Keys
 * ************** */
bool is_qwerty = true;
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
  0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
  0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
  0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
  0x00
};

static const char PROGMEM logo_slave[] = {
  0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
  0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
  0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
  0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
  0x0c, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x0e,
  0x1d, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0f,
  0x1d, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0f,
  0x1c, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1f,
  0x00
};

static const char PROGMEM logo_footer[] = {
  0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
  0x00
};

static const char PROGMEM logo_os_1[][3] = {
  {0x20, 0x21, 0},
  {0x91, 0x92, 0}
};

static const char PROGMEM logo_os_2[][3] = {
  {0x30, 0x31, 0},
  {0xa1, 0xa2, 0}
};

static const char PROGMEM logo_lo_1[][3] = {
  {0x22, 0x23, 0},
  {0x93, 0x94, 0}
};

static const char PROGMEM logo_lo_2[][3] = {
  {0x32, 0x33, 0},
  {0xa3, 0xa4, 0}
};

static const char PROGMEM logo_la_1[][3] = {
  {0x95, 0x96, 0}, // qwerty
  {0x95, 0x96, 0}, // colemak-dh
  {0x2e, 0x2f, 0}, // mouse
  {0x2c, 0x2d, 0}, // navigation
  {0x28, 0x29, 0}, // adjust
  {0x26, 0x27, 0}, // symbol
  {0x24, 0x25, 0}, // number
  {0x2a, 0x2b, 0}, // function
};

static const char PROGMEM logo_la_2[][3] = {
  {0xa5, 0xa6, 0}, // qwerty
  {0xa5, 0xa6, 0}, // colemak-dh
  {0x3e, 0x3f, 0}, // mouse
  {0x3c, 0x3d, 0}, // navigation
  {0x38, 0x39, 0}, // adjust
  {0x36, 0x37, 0}, // symbol
  {0x34, 0x35, 0}, // number
  {0x3a, 0x3b, 0}, // function
};

static const char PROGMEM logo_mo_sft_1[][3] = {
  {0x99, 0x9a, 0},
  {0x04, 0x05, 0}
};

static const char PROGMEM logo_mo_sft_2[][3] = {
  {0xa9, 0xaa, 0},
  {0x14, 0x15, 0}
};

static const char PROGMEM logo_mo_ctr_1[][3] = {
  {0x97, 0x98, 0},
  {0x02, 0x03, 0}
};

static const char PROGMEM logo_mo_ctr_2[][3] = {
  {0xa7, 0xa8, 0},
  {0x12, 0x13, 0}
};

static const char PROGMEM logo_mo_alt_1[][3] = {
  {0x9b, 0x9c, 0},
  {0x06, 0x07, 0}
};

static const char PROGMEM logo_mo_alt_2[][3] = {
  {0xab, 0xac, 0},
  {0x16, 0x17, 0}
};

static const char PROGMEM logo_mo_gui_1[][3] = {
  {0x9d, 0x9e, 0},
  {0x08, 0x09, 0}
};

static const char PROGMEM logo_mo_gui_2[][3] = {
  {0xad, 0xae, 0},
  {0x18, 0x19, 0}
};

static const char PROGMEM logo_l_1[] = {0x90, 0};
static const char PROGMEM logo_l_2[] = {0xa0, 0};
static const char PROGMEM logo_r_1[] = {0x9f, 0};
static const char PROGMEM logo_r_2[] = {0xaf, 0};

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    const uint8_t mod = get_mods();
    const uint8_t sft = (mod & MOD_MASK_SHIFT) ? 1 : 0;
    const uint8_t ctr = (mod & MOD_MASK_CTRL) ? 1 : 0;
    const uint8_t alt = (mod & MOD_MASK_ALT) ? 1 : 0;
    const uint8_t gui = (mod & MOD_MASK_GUI) ? 1 : 0;

    uint8_t layer = get_highest_layer(layer_state);
    if (layer == 0 && !is_qwerty) layer = 1;

    oled_write_P(logo_header, false);
    oled_write_P(logo_l_1, false);
    oled_write_P(logo_os_1[is_mac], false);
    oled_write_P(logo_lo_1[is_qwerty], false);
    oled_write_P(logo_la_1[layer], false);
    oled_write_P(logo_mo_sft_1[sft], false);
    oled_write_P(logo_mo_ctr_1[ctr], false);
    oled_write_P(logo_mo_alt_1[alt], false);
    oled_write_P(logo_mo_gui_1[gui], false);
    oled_write_P(logo_r_1, false);
    oled_write_P(logo_l_2, false);
    oled_write_P(logo_os_2[is_mac], false);
    oled_write_P(logo_lo_2[is_qwerty], false);
    oled_write_P(logo_la_2[layer], false);
    oled_write_P(logo_mo_sft_2[sft], false);
    oled_write_P(logo_mo_ctr_2[ctr], false);
    oled_write_P(logo_mo_alt_2[alt], false);
    oled_write_P(logo_mo_gui_2[gui], false);
    oled_write_P(logo_r_2, false);
    oled_write_P(logo_footer, false);
  } else {
    oled_write_P(logo_slave, false);
  }

  return false;
}

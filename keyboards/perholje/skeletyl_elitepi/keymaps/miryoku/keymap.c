// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "process_tap_dance.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_MEDIA,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
};

// Tap-dance
enum {
    TD_RESET = 0,
    TD_CAPS,
};

void safe_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        // Reset the keyboard if you tap the key more than 2 times
        reset_keyboard();
        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset),
    [TD_CAPS]  = ACTION_TAP_DANCE_DOUBLE(QK_CAPS_WORD_TOGGLE, KC_CAPS_LOCK),
};

// Homerow mods
#define SUP_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTRL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)
#define SHFT_N LSFT_T(KC_N)
#define CTRL_E LCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define SUP_O LGUI_T(KC_O)
#define RALT_X RALT_T(KC_X)
#define RALT_DOT RALT_T(KC_DOT)

// Layer switch
#define DEL_FUN LT(LAYER_FUNCTION, KC_DEL)
#define BSP_NUM LT(LAYER_NUMERAL, KC_BSPC)
#define TAB_SYM LT(LAYER_SYMBOLS, KC_TAB)
#define ENT_MOU LT(LAYER_POINTER, KC_ENT)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define ESC_MED LT(LAYER_MEDIA, KC_ESC)

#define RELOAD TD(TD_RESET)
#define CAPWRD QK_CAPS_WORD_TOGGLE // TD(TD_CAPS)

#define U_UND LCTL(KC_Z)
#define U_RDO LCTL(KC_Y)
#define U_CUT LSFT(KC_DEL)
#define U_CPY LCTL(KC_INS)
#define U_PST LSFT(KC_INS)
#define U_SNUBS LSFT(KC_NUBS)

#define ____________RIGHT_R1_BLANK________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RELOAD,
#define ____________RIGHT_R2_BLANK________________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
#define ____________RIGHT_R3_BLANK________________ XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
#define ______________LEFT_R1_BLANK________________ RELOAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
#define ______________LEFT_R2_BLANK________________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
#define ______________LEFT_R3_BLANK________________ XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,
#define ______BLANK_THUMBS_______ XXXXXXX, XXXXXXX, XXXXXXX

// clang-format off
// Miryoku Colemak-DH
#define LAYOUT_LAYER_BASE                                                                         \
    KC_Q,	 KC_W,	  KC_F,	   KC_P,    KC_B,	    KC_J,	 KC_L,    KC_U,    KC_Y,    KC_QUOT,  \
    SUP_A,	 ALT_R,	  CTRL_S,  SHFT_T,  KC_G,	    KC_M,	 SHFT_N,  CTRL_E,  ALT_I,   SUP_O,    \
    KC_Z,	 RALT_X,  KC_C,    KC_D,    KC_V,	    KC_K,	 KC_H,	  KC_COMM, RALT_DOT,KC_SLSH,  \
                      DEL_FUN, BSP_NUM, TAB_SYM,    ENT_MOU, SPC_NAV, ESC_MED

#define LAYOUT_LAYER_NAVIGATION                                                                   \
    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_INS,     ____________RIGHT_R1_BLANK________________    \
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CAPWRD,     ____________RIGHT_R2_BLANK________________    \
    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,      ____________RIGHT_R3_BLANK________________    \
                      KC_DEL,  KC_BSPC, KC_TAB,     ______BLANK_THUMBS_______

#define LAYOUT_LAYER_POINTER                                                                      \
    KC_WH_U, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,    ____________RIGHT_R1_BLANK________________    \
    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,    ____________RIGHT_R2_BLANK________________    \
    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,      ____________RIGHT_R3_BLANK________________    \
             KC_MS_BTN3, KC_MS_BTN1,  KC_MS_BTN2,   ______BLANK_THUMBS_______

#define LAYOUT_LAYER_MEDIA                                                                        \
    XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,    ____________RIGHT_R1_BLANK________________    \
    XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, MU_TOGG,    ____________RIGHT_R2_BLANK________________    \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    ____________RIGHT_R3_BLANK________________    \
                      KC_MUTE, KC_MPLY, KC_MSTP,    ______BLANK_THUMBS_______

#define LAYOUT_LAYER_NUMERAL                                                                      \
    ______________LEFT_R1_BLANK________________     KC_NUBS, KC_7,    KC_8,    KC_9,    KC_LBRC,  \
    ______________LEFT_R2_BLANK________________     KC_EQL,  KC_4,    KC_5,    KC_6,    KC_SCLN,  \
    ______________LEFT_R3_BLANK________________     KC_BSLS, KC_1,    KC_2,    KC_3,    KC_GRV,   \
                      ______BLANK_THUMBS_______,    KC_MINS, KC_0,    KC_DOT

#define LAYOUT_LAYER_SYMBOLS                                                                      \
    ______________LEFT_R1_BLANK________________     U_SNUBS, KC_AMPR, KC_ASTR, KC_LPRN, KC_LCBR,  \
    ______________LEFT_R2_BLANK________________     KC_PLUS, KC_DLR,  KC_PERC, KC_CIRC, KC_COLN,  \
    ______________LEFT_R3_BLANK________________     KC_PIPE, KC_EXLM, KC_AT,   KC_HASH, KC_TILD,  \
                      ______BLANK_THUMBS_______,    KC_UNDS, KC_LPRN, KC_RPRN

#define LAYOUT_LAYER_FUNCTION                                                                     \
    ______________LEFT_R1_BLANK________________     KC_PSCR, KC_F7,   KC_F8,   KC_F9,   KC_F12,   \
    ______________LEFT_R2_BLANK________________     KC_SCRL, KC_F4,   KC_F5,   KC_F6,   KC_F11,   \
    ______________LEFT_R3_BLANK________________     KC_PAUS, KC_F1,   KC_F2,   KC_F3,   KC_F10,   \
                      ______BLANK_THUMBS_______,    KC_TAB,  KC_SPC,  KC_APP

#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE]        = LAYOUT_wrapper(LAYOUT_LAYER_BASE),
    [LAYER_NAVIGATION]  = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
    [LAYER_POINTER]     = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
    [LAYER_MEDIA]       = LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
    [LAYER_NUMERAL]     = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
    [LAYER_SYMBOLS]     = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
    [LAYER_FUNCTION]    = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
};
// clang-format on

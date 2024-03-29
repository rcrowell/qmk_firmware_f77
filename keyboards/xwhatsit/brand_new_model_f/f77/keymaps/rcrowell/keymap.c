/* Copyright 2020 Purdea Andrei
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _Q0,
    _C0,
    _QM,
    _FN,
    _VS,
    _TT
};

enum {
  TD_XTRM = 0
};

#define MY_LCTL LM(_QM, MOD_LCTL)
#define MY_LALT LM(_QM, MOD_LALT)
#define MY_LGUI LM(_QM, MOD_LGUI)
#define MY_RALT LM(_QM, MOD_LALT)
#define MY_RGUI LM(_QM, MOD_LGUI)

#define MY_XT_S LCTL(KC_S)
#define MY_XT_Q LCTL(KC_Q)
#define MY_PAUS TD(TD_XTRM)
#define MY_TTY1 LCTL(LALT(KC_F1))
#define MY_TTY2 LCTL(LALT(KC_F2))
#define MY_TTY3 LCTL(LALT(KC_F3))
#define MY_TTY4 LCTL(LALT(KC_F4))
#define MY_TTY5 LCTL(LALT(KC_F5))
#define MY_TTY6 LCTL(LALT(KC_F6))


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_XTRM] = ACTION_TAP_DANCE_DOUBLE(MY_XT_S, MY_XT_Q)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_Q0] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_MUTE, KC_VOLD, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_MPRV, KC_MPLY, KC_MNXT, 
        MY_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_HOME, KC_END,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_FN),                   MY_PAUS, KC_UP,   KC_PGDN,
        KC_LCTL, MY_LALT, MY_LGUI, KC_SPC,  MY_RGUI, MY_RALT, MO(_FN),                                                                         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Tarmak[0] with "QWERTY" mods -- activate QWERTY when ctl/alt/gui are on
    [_C0] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_J,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_M,    KC_N,    KC_E,    _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_K,    KC_H,    _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                                                         _______, _______, _______
    ),
    // "QWERTY" mods -- undo all colemak changes
    [_QM] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_E,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_H,    KC_J,    KC_K,    _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_M,    KC_N,    _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                                                         _______, _______, _______
    ),
    // Function layer that only lets mods shine through
    [_FN] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_DEL,  KC_MPLY, KC_MPRV, KC_MNXT,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_RGHT, XXXXXXX,                   XXXXXXX, RESET,   XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, _______, _______,                   XXXXXXX, KC_PGUP, XXXXXXX,
        _______, KC_LGUI, KC_LALT, XXXXXXX, KC_RALT, KC_RGUI, _______,                                                                         KC_HOME, KC_PGDN, KC_END
    ),
    // Helpful junk for the day job
    [_VS] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                                                         _______, _______, _______
    ),
    // Helpful shortcuts for changing ttys
    [_TT] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        _______, MY_TTY1, MY_TTY2, MY_TTY3, MY_TTY4, MY_TTY5, MY_TTY6, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_SLCK, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                                                         _______, _______, _______
    )
};

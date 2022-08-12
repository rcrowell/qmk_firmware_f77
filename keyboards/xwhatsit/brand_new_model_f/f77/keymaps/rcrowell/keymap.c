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
    _QW,
    _CK,
    _FN,
    _VS
};

#define MY_CAD  LALT(LCTL(KC_DEL))
#define MY_CAPS LCTL_T(KC_CAPS)
#define MY_LCTL LM(_QW, MOD_LCTL)
#define MY_LALT LM(_QW, MOD_LALT)
#define MY_LGUI LM(_QW, MOD_LGUI)
#define MY_RALT LM(_QW, MOD_LALT)
#define MY_RGUI LM(_QW, MOD_LGUI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_MUTE, KC_VOLD, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          XXXXXXX, KC_PSCR, KC_PGUP,
        MY_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    DF(_CK), MY_CAD,  KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_ESC,                    KC_HOME, KC_UP,   KC_END,
        MO(_FN), MY_LGUI, MY_LALT, KC_SPC,  MY_RALT, MY_RGUI, MO(_FN),                                                                         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_CK] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,  KC_MUTE, KC_VOLD, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_J,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          TG(_VS), KC_PSCR, KC_PGUP,
        MY_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_M,    KC_N,    KC_E,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    DF(_QW), MY_CAD,  KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_ESC,                    KC_HOME, KC_UP,   KC_END,
        MO(_FN), MY_LGUI, MY_LALT, KC_SPC,  MY_RALT, MY_RGUI, MO(_FN),                                                                         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,           XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RESET,   XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,                   XXXXXXX, KC_PGUP, XXXXXXX,
        _______, KC_LGUI, KC_LALT, XXXXXXX, KC_RALT, KC_RGUI, _______,                                                                         KC_HOME, KC_PGDN, KC_END
    ),
    [_VS] = LAYOUT_ansi_hhkb_split_shift_split_backspace(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,                                                                         _______, _______, _______
    )
};

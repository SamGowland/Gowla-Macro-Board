/* Copyright 2021 Gowla
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        LT(1, KC_MPRV), KC_MNXT, KC_MPLY,
        KC_VOLD,        	KC_UP,   KC_VOLU,
        KC_LEFT,        KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_ortho_3x3(
        KC_ESC,  KC_MPLY, RESET,
        RGB_MODE_RGBTEST,   RGB_MODE_RAINBOW,   RGB_MODE_KNIGHT,
        RGB_MODE_PLAIN,   KC_F3,   KC_F4
    )
};

void encoder_update_kb(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
		  tap_code(KC_VOLU);
		} else {
		  tap_code(KC_VOLD);
		}
	}
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
	// led hue, sat, val, led
	rgblight_sethsv_range(HSV_CYAN, 0, 2);
	rgblight_sethsv_noeeprom(HSV_CYAN);
}
#endif


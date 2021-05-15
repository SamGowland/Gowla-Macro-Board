#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        KC_VOLD, KC_MPLY, KC_VOLU,
        KC_VOLD,        KC_MPLY,   KC_VOLU,
        KC_VOLD,        KC_MPLY, KC_VOLU
    ),
    [1] = LAYOUT_ortho_3x3(
        KC_ESC,  KC_MPLY, RESET,
        KC_P7,   KC_P1,   KC_F1,
        KC_F2,   KC_F3,   KC_F4
    )
};

void encoder_update_kb(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
		switch(biton32(layer_state)){
			case 1: //Layer 1
				if (clockwise){
					tap_code(KC_DOWN);
				} else{
					tap_code(KC_UP);
				}
				break;
			default: // All other layers
				if (clockwise) {
					tap_code(KC_VOLU);
				} else {
					tap_code(KC_VOLD);
				break;
		}
	}
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
	// led hue, sat, val, led
	sethsv(HSV_CYAN, (LED_TYPE *)&led[0]); // led 0
	sethsv(HSV_CYAN,   (LED_TYPE *)&led[1]); // led 1
	rgblight_sethsv_noeeprom(HSV_CYAN);
}
#endif


// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define ____ KC_TRNS

#ifdef AUTO_SHIFT_ENABLE

void keyboard_post_init_user(void) {
	autoshift_disable();
}
#endif

//
// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
//
// Gemäss Tester: https://en.key-test.ru/
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT(
//            KC_CLEAR,        KC_LEFT_PAREN,    KC_RIGHT_PAREN,    KC_BACKSPACE,
//			  KC_CALC,         KC_AUDIO_VOL_UP,  KC_AUDIO_MUTE,     KC_AUDIO_VOL_DOWN,
			KC_SCROLL_LOCK,  KC_PAUSE,         KC_HOME,           KC_END,
            
            KC_NUM,          KC_KP_SLASH,      KC_KP_ASTERISK,    KC_KP_MINUS, 
            KC_KP_7,         KC_KP_8,          KC_KP_9,
            KC_KP_4,         KC_KP_5,          KC_KP_6,           KC_KP_PLUS,
            KC_KP_1,         KC_KP_2,          KC_KP_3,
            KC_KP_0,         KC_KP_DOT,                           KC_KP_ENTER
		)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
	// Create OLED content
    oled_advance_page(true);
    oled_write_P(PSTR("Lotus -58-"), false);
    oled_advance_page(true);

    // Print current layer
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("-Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("-Func\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("-Num \n"), false);
            break;
        case 3:
            oled_write_P(PSTR("-Sys \n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
	
	// Display capslock
    oled_advance_page(true);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("Caps- lock"), led_usb_state.caps_lock);
	
#ifdef AUTO_SHIFT_ENABLE

	bool autoshift = get_autoshift_state();
	oled_advance_page(true);
	oled_write_P(PSTR("Auto-Shift"), autoshift);
	oled_advance_page(true);
	
#endif

}

bool oled_task_user(void) {
    print_status_narrow();
	return false;
}

#endif
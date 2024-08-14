// Copyright 2023 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Include print stuff if I turn on console for debugging
#if defined(CONSOLE_ENABLE)

#include <print.h>
#include <string.h>

#endif

enum layers {
    BASE = 0,
    MACRO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_MUTE,
        KC_P1,        KC_P2,    KC_P3,
        KC_P4,        KC_P5,    KC_P6,
        LT(1, KC_P7), KC_P8,    KC_P9
    ),
    [MACRO] = LAYOUT(
        RGB_TOG,
        RGB_HUI,      RGB_SAI,  RGB_SPI,
        RGB_HUD,      RGB_SAD,  RGB_SPD,
        _______,      RGB_MOD,  RGB_RMOD
    )
};


// RGB Matrix - Overriden to specify colors for each layer
#if defined(RGB_MATRIX_ENABLE)

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case BASE:
                rgb_matrix_set_color(i, RGB_WHITE);
                break;
            case MACRO:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            default:
                break;
        }
    }
    return false;
}

#endif

// Encoder
#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MACRO] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};

#endif

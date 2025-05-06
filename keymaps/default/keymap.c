/* MIT License

Copyright (c) 2023 Florian Brandner

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include "config.h"
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    // RAG: Right Alt + Right GUI
    // RSG: Right Shift + Right GUI
    TO(_RGB),        RSG(KC_F1),         RSG(KC_F2),    RSG(KC_F3),
    RCTL(KC_F13),    RCTL(KC_F14),    RCTL(KC_F15),
    RCTL(KC_F16),    RCTL(KC_F17),    RCTL(KC_F18),   LCA(KC_F20),
    RCTL(KC_F19),    RCTL(KC_F20),    RCTL(KC_F21),
    RCTL(KC_F22),    RCTL(KC_F23),    RCTL(KC_F24),   LCA(KC_F21)
  ),
  [_RGB] = LAYOUT(
    TO(_BASE), RGB_TOG ,   XXXXXXX,   XXXXXXX,
    RGB_RMOD,  RGB_MOD,    XXXXXXX,
    RGB_HUD,   RGB_HUI,    XXXXXXX,   RGB_SPI,
    RGB_SAD,   RGB_SAI,    XXXXXXX,
    RGB_VAD,   RGB_VAI,    XXXXXXX,   RGB_SPD
  ),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;  // flips the display 270 degrees
}

bool oled_task_user(void) {
  // Layer Status
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("[BAS]"), false);
      break;
    // case _GAME:
    //   oled_write_P(PSTR("[GAM]"), false);
    //   break;
    case _RGB:
      oled_write_P(PSTR("[RGB]"), false);
      break;
    default:
      oled_write_P(PSTR("[-?-]"), false);
  }

  // RGB backlight status
  oled_write_P(PSTR("-----"), false);
  static char led_buf[50];
  snprintf(led_buf, sizeof(led_buf) - 1, "RGB:%cM:%3dH:%3dS:%3dV:%3dE:%3d\n",
    rgblight_is_enabled() ? '*' : '.', (uint8_t)rgblight_get_mode(),
    rgblight_get_hue(),
    rgblight_get_sat(),
    rgblight_get_val(),
    rgblight_get_speed()
  );
  oled_write(led_buf, false);

  return false;
}
#endif

#ifdef ENCODER_ENABLE
// bool encoder_update_user(uint8_t index, bool clockwise) {
//   if (clockwise) {
//     tap_code_delay(KC_VOLU, 1);
//   } else {
//     tap_code_delay(KC_VOLD, 1);
//   }
//   return true;
// }

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if(active) { // Press
        tap_code(KC_KB_MUTE);
      } else { // Release
      }
      break;
  }
  return true;
}

#endif

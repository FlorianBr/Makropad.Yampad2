/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5950 // YP
#define PRODUCT_ID      0x8369
#define DEVICE_VER      0x0001
#define MANUFACTURER    Mattia Dal Ben
#define PRODUCT         Yampad

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B1, B3, B2, B6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Underlight configuration */
#define RGB_DI_PIN F4
#define RGBLED_NUM 9
#define RGBLIGHT_ANIMATIONS

#define RGBLIGHT_HUE_STEP 	10
#define RGBLIGHT_SAT_STEP 	10
#define RGBLIGHT_VAL_STEP   10
#define RGBLIGHT_LIMIT_VAL 255

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 2


/* The settings for the hard coded encoder */
#define ENCODERS_PAD_A { F1 }
#define ENCODERS_PAD_B { F0 }
#define DIP_SWITCH_PINS { C7 }

/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "HAL.h"
#include "../../lcd/ultralcd.h"

#define XPT2046_DFR_MODE        0x00
#define XPT2046_SER_MODE        0x04
#define XPT2046_CONTROL         0x80

#define XPT2046_X               0x10
#define XPT2046_Z1              0x30
#define XPT2046_Z2              0x40
#define XPT2046_Y               0x50

#define XPT2046_SPI_CLOCK       SPI_CLOCK_DIV2

#define XPT2046_Z1_TRESHHOLD    10

/* MKS Robin TFT v2.0 */
#define XPT2046_X_CALIBRATION    12013
#define XPT2046_X_OFFSET           -32
#define XPT2046_Y_CALIBRATION    -8711
#define XPT2046_Y_OFFSET           256

/* MKS Robin TFT v1.1 */
//#define XPT2046_X_CALIBRATION   -11792
//#define XPT2046_X_OFFSET           342
//#define XPT2046_Y_CALIBRATION     8947
//#define XPT2046_Y_OFFSET           -19

uint8_t xpt2046_read_buttons();
uint16_t getTouchCoordinate(uint8_t coordinate);
bool getTouchPoint(uint16_t *x, uint16_t *y);

inline bool isTouched() { return getTouchCoordinate(XPT2046_Z1) >= XPT2046_Z1_TRESHHOLD; }
inline void waitForRelease(void) { while (isTouched()) {}; }
inline void waitForTouch(uint16_t *x, uint16_t *y) { while(!getTouchPoint(x, y)) {}; }

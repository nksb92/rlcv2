#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include "dmx.h"
#include "pdc.h"
#include "common.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32 

#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 

void init_display(Adafruit_SSD1306& dp);

void hsv_display_update(Adafruit_SSD1306& dp, C_HSV out_val);

void dmx_display_update(Adafruit_SSD1306& dp, rgb_dmx dmx_val);

void pdc_display_update(Adafruit_SSD1306& dp, pdc_page pdc_val);

#endif
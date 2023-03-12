#ifndef RLC_V2_H
#define RLC_V2_H

#include "dmx.h"
#include "leds.h"
#include "rotary_encoder.h"
#include "display.h" 
#include "common.h"

EncoderButton enc_button(DT_PIN, CLK_PIN, SW_PIN);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#endif
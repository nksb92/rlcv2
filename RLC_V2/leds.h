#ifndef LEDS_H
#define LEDS_H

#include "common.h"

#define RED_PIN 10
#define GREEN_PIN 9
#define BLUE_PIN 8

void init_led();

void rgb_out(CRGB led_val);

void hsv_out(C_HSV hsv_val);

#endif
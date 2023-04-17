#ifndef LEDS_H
#define LEDS_H

#include "common.h"

#define RED_PIN 10
#define GREEN_PIN 9
#define BLUE_PIN 8

/**
 * Initializes the LED pins as outputs.
 */
void init_led();

/**
 * Ramps up the brightness of an HSV LED from 0 to its value parameter.
 *
 * @param led_val: An HSV value representing the target brightness.
 */
void ramp_up(C_HSV led_val);

/**
 * Sets the output of an RGB LED with the given value and scaling factor.
 *
 * @param led_val: The target RGB value.
 * @param factor: The scaling factor to apply to the LED.
 */
void rgb_out(CRGB led_val, uint8_t factor);

/**
 * Sets the output of an HSV LED with the given value.
 *
 * @param hsv_val: The target HSV value.
 */
void hsv_out(C_HSV hsv_val);

#endif
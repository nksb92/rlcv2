#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
// https://github.com/Stutchbury/EncoderButton Encoder Libary
#include "Arduino.h"
#include <EncoderButton.h>
#include "common.h"

// These defines are used to specify the pin numbers for the switch,
// data, and clock pins of the rotary encoder.

// The pin number for the switch pin of the rotary encoder
#define SW_PIN 2

// The pin number for the DT (data) pin of the rotary encoder
#define DT_PIN 3

// The pin number for the CLK (clock) pin of the rotary encoder
#define CLK_PIN 4

/**
 * Initialize the rotary encoder module with the specified EncoderButton object.
 *
 * @param eb: The EncoderButton object to use for handling button events.
 */
void init_encoder(EncoderButton& eb);

/**
 * Handle the rotary encoder events. If the rotary encoder is not in standby mode,
 * increment the encoder value by the current encoder value.
 *
 * @param eb: The EncoderButton object associated with the rotary encoder.
 */
void encoder_handler(EncoderButton& eb);

/**
 * Handle the long press button event. If the rotary encoder is not in standby mode,
 * call the "next" function of the "main_sw" object.
 *
 * @param eb: The EncoderButton object associated with the rotary encoder.
 */
void long_press_handler(EncoderButton& eb);

/**
 * Handle the button press event. If the rotary encoder is not in standby mode,
 * set the "next" flag to true.
 *
 * @param eb: The EncoderButton object associated with the rotary encoder.
 */
void press_handler(EncoderButton& eb);

/**
 * Handle the double press button event. Currently does nothing.
 *
 * @param eb: The EncoderButton object associated with the rotary encoder.
 */
void double_press_handler(EncoderButton& eb);

/**
 * Returns the current status of the "change" flag.
 *
 * @return: The current value of the "change" flag.
 */
bool get_event_status();

/**
 * Sets the value of the "change" flag.
 *
 * @param state: The value to set the "change" flag to.
 */
void set_event_status(bool state);

/**
 * Sets the standby state of the rotary encoder module.
 *
 * @param state: The value to set the standby state to.
 */
void set_dspl_standby(bool state);

/**
 * Returns the current state of the "main_sw" object.
 *
 * @return: The current state of the "main_sw" object.
 */
uint8_t get_main_state();

/**
 * Returns the current value of the "next" flag.
 *
 * @return: The current value of the "next" flag.
 */
bool get_next_state();

/**
 * Sets the value of the "next" flag.
 *
 * @param state: The value to set the "next" flag to.
 */
void set_next_state(bool state);

/**
 * Returns the current value of the rotary encoder and resets the encoder value to zero.
 *
 * @return: The current value of the rotary encoder.
 */
int16_t get_encoder_val();

#endif
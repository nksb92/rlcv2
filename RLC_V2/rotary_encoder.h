#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
// https://github.com/Stutchbury/EncoderButton Encoder Libary
#include "Arduino.h"
#include <EncoderButton.h>
#include "common.h"

#define SW_PIN 2
#define DT_PIN 3
#define CLK_PIN 4

void init_encoder(EncoderButton& eb);

void encoder_handler(EncoderButton& eb);

void long_press_handler(EncoderButton& eb);

void press_handler(EncoderButton& eb);

void double_press_handler(EncoderButton& eb);

bool get_event_status();

void set_event_status(bool state);

void set_dspl_standby(bool state);

uint8_t get_main_state();

bool get_next_state();

void set_next_state(bool state);

int16_t get_encoder_val();

#endif
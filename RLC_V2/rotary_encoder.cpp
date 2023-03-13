#include "rotary_encoder.h"

#define ENC_STEP 1

volatile int16_t enc_val = 0;
bool change = true;
bool standby = false;
bool next = false;

main main_sw;

void init_encoder(EncoderButton& eb) {
  eb.setClickHandler(press_handler);
  eb.setDoubleClickHandler(double_press_handler);
  eb.setLongClickHandler(long_press_handler);
  eb.setEncoderHandler(encoder_handler);
  eb.setLongClickDuration(500);
  change = true;
}

void encoder_handler(EncoderButton& eb) {
  if (!standby) {
    enc_val += eb.increment();
  }
  change = true;
}

void long_press_handler(EncoderButton& eb) {
  if (!standby) {
    main_sw.next();
  }
  change = true;
}

void press_handler(EncoderButton& eb) {
  if (!standby) {
    next = true;
  }
  change = true;
}

void double_press_handler(EncoderButton& eb) {
  if (!standby) {
  }
  change = true;
}

bool get_event_status() {
  return change;
}

void set_event_status(bool state) {
  change = state;
}

void set_dspl_standby(bool state) {
  standby = state;
}

uint8_t get_main_state() {
  return main_sw.get_current();
}

bool get_next_state(){
  return next;
}

void set_next_state(bool state){
  next = state;
}

int16_t get_encoder_val() {
  int16_t temp = enc_val;
  enc_val = 0;
  return temp;
}
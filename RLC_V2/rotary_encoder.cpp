#include "rotary_encoder.h"

#define ENC_STEP 5

volatile uint8_t led_value = 0;
bool change = true;

void init_encoder(EncoderButton& eb){
  eb.setClickHandler(press_handler);
  eb.setDoubleClickHandler(double_press_handler);
  eb.setLongClickHandler(long_press_handler);
  eb.setEncoderHandler(encoder_handler);
  eb.setLongClickDuration(500);
}

void encoder_handler(EncoderButton& eb) {
  if (eb.increment() > 0) {
    led_value += ENC_STEP;
  } else {
    led_value -= ENC_STEP;
  }
  change = true;
}

void long_press_handler(EncoderButton& eb){
    change = true;
}

void press_handler(EncoderButton& eb){
    change = true;

}

void double_press_handler(EncoderButton& eb){
    change = true;

}

bool get_event_status(){
  return change;
}

void set_event_status(bool state){
  change = state;
}
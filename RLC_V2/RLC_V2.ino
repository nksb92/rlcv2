#include "RLC_V2.h"

uint8_t state = 0;
int16_t encoder_val = 0;
uint8_t main_state = 0;
uint8_t hsv_state = 0;
unsigned long last_millis;

CRGB dmx_val(255, 255, 255);

void setup() {
  Serial.begin(115200);
  Serial.println("Startup");
  init_dmx();
  init_led();
  init_display(display);
  init_encoder(enc_button);
  delay(500);
  last_millis = millis();
}

void loop() {
  enc_button.update();
  encoder_val = get_encoder_val();
  main_state = get_main_state();
  change_vals = get_event_status();

  switch (main_state) {
    case HSV:
      hsv_state = get_hsv_state();
      switch (hsv_state) {
        case HUE:
          hsv_val.add_hue(encoder_val);
          break;
        case SAT:
          hsv_val.add_sat(encoder_val);
          break;
        case VAL:
          hsv_val.add_val(encoder_val);
          break;
      }
      break;
  }

  if (millis() - last_millis >= 10) {
    // hsv_display_update(display, hsv_val, get_hsv_state());
    last_millis = millis();
  }
  if (change_vals) {
    Serial.println(hsv_val.hue);
    hsv_display_update(display, hsv_val, get_hsv_state());
    change_vals = false;
    set_event_status(change_vals);
  }
}

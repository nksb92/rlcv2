#include "RLC_V2.h"

int16_t encoder_val = 0;
uint8_t main_state = 1;
volatile uint8_t hsv_state = 0;
unsigned long last_millis;

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

  if (change_vals) {
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
        hsv_display_update(display, hsv_val, hsv_state);
        break;
      case DMX:
        dmx_val.add_to_adress(encoder_val);
        dmx_display_update(display, dmx_val);
        break;
    }
    change_vals = false;
    last_millis = millis();
    set_event_status(change_vals);
  }

  if (millis() - last_millis >= 30000) {
    display.clearDisplay();
    display.display();
  }
}

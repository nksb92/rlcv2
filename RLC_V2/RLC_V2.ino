#include "RLC_V2.h"

uint8_t state = 0;
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
  if (millis() - last_millis >= 1000) {
    state++;
    if (state >= 3){
      state = 0;
    } 

    hsv_display_update(display, hsv_val, state);

    last_millis = millis();
  }
  change_vals = get_event_status();

  if (change_vals) {
    // Serial.println(dmx_val[0]);
    hsv_display_update(display, hsv_val, state);
    change_vals = false;
    set_event_status(change_vals);
  }
}

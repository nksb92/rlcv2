#include "RLC_V2.h"

void setup() {
  Serial.begin(115200);
  
  init_dmx();
  init_led();
  init_display(display);
  init_encoder(eb1);
}

void loop() {
  eb1.update();
  if (change_vals) {
    hsv_display_update(display, hsv_val);
    change_vals = false;
  }
  get_event_status(change_vals);
}

#include "RLC_V2.h"

int16_t encoder_val = 0;
uint8_t main_state = 1;
volatile uint8_t hsv_state = 0;
unsigned long last_millis;
uint16_t standby_time = 30000;
C_HSV hsv_val(0, 100, 50);
bool change_vals = true;
rgb_dmx dmx_val(CRGB(0, 0, 0));

void setup() {
  Serial.begin(115200);
  Serial.println("Startup");
  init_led();
  init_display(display);
  init_encoder(enc_button);
  dmx_val.install_dmx();
  delay(500);
  last_millis = millis();
}

void loop() {
  enc_button.update();
  change_vals = get_event_status();

  main_state = get_main_state();
  hsv_state = get_hsv_state();
  encoder_val = get_encoder_val();

  // hanlde everthing periodically
  switch (main_state) {
    case DMX:
      dmx_val.hanlde_dmx();
      rgb_out(dmx_val.get_dmx_message());
      break;
  }

  // handle everything on event
  if (change_vals) {
    switch (main_state) {
      case HSV:
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
        hsv_out(hsv_val);
        hsv_display_update(display, hsv_val, hsv_state);
        break;
      case DMX:
        dmx_val.add_to_adress(encoder_val);
        dmx_display_update(display, dmx_val);
        break;
    }
    change_vals = false;
    set_dspl_standby(false);
    last_millis = millis();
    set_event_status(change_vals);
  }

  // no action for 30 secs will set the display in standby mode
  if (millis() - last_millis >= standby_time) {
    set_dspl_standby(true);
    display.clearDisplay();
    display.display();
  }
}

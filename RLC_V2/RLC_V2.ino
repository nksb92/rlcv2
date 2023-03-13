#include "RLC_V2.h"

int16_t encoder_val = 0;
uint8_t main_state = 1;
unsigned long last_millis;
uint16_t standby_time = 30000;

bool change_vals = true;
bool next_change = false;

C_HSV hsv_val(0, 100, 100);
rgb_dmx dmx_val(CRGB(0, 0, 0));
pdc_page pdc(0);

EncoderButton enc_button(DT_PIN, CLK_PIN, SW_PIN);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Serial.println("Startup");

  init_led();
  init_display(display);
  init_encoder(enc_button);
  dmx_val.install_dmx();

  ramp_up(hsv_val);
  last_millis = millis();
}

void loop() {
  enc_button.update();
  change_vals = get_event_status();
  next_change = get_next_state();

  main_state = get_main_state();
  encoder_val = get_encoder_val();

  // hanlde everthing periodically
  switch (main_state) {
    case DMX:
      dmx_val.hanlde_dmx();
      rgb_out(dmx_val.get_dmx_message(), 255);
      break;
  }

  // cycle through display options
  if (next_change) {
    switch (main_state) {
      case HSV:
        hsv_val.next();
        break;
      case PDC:
        pdc.next();
        break;
      default:
        break;
    }
    set_next_state(false);
  }

  // handle everything on event
  if (change_vals) {
    switch (main_state) {
      case HSV:
        switch (hsv_val.get_current()) {
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
        hsv_display_update(display, hsv_val);
        break;
      case DMX:
        dmx_val.add_to_adress(encoder_val);
        dmx_display_update(display, dmx_val);
        break;
      case PDC:
        pdc.add_bright(encoder_val);
        rgb_out(pdc.get_current_color(), pdc.get_bright());
        pdc_display_update(display, pdc);
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

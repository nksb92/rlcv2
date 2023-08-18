#include "RLC_V2.h"

int16_t encoder_val = 0;
uint8_t main_state = 1;
unsigned long last_millis;
unsigned long saved_timer_start;
uint16_t standby_time = 30000;
uint16_t display_saved_time = 2000;

bool display_saved = false;
bool change_vals = true;
bool button_pressed = false;
bool button_long_pressed = false;
bool button_double_pressed = false;

C_HSV hsv_val(STD_HUE, STD_SAT_P, STD_VAL_P);
C_RGB rgb_val(STD_RED, STD_GREEN, STD_BLUE);
rgb_dmx dmx_val(CRGB(0, 0, 0));
pdc_page pdc(STD_CURRENT);
main main_sw;

EncoderButton enc_button(DT_PIN, CLK_PIN, SW_PIN);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Serial.println("Startup");

  init_eeprom();
  init_led();
  init_display(display);
  init_encoder(enc_button);
  dmx_val.install_dmx();

  read_eeprom(hsv_val, rgb_val, dmx_val, pdc, main_sw);

  display_startup(display);
  ramp_up(hsv_val, rgb_val, pdc, main_sw);
  Serial.println("Startup complete.");

  last_millis = millis();
  saved_timer_start = millis();
}

void loop() {
  enc_button.update();
  change_vals = get_event_status();
  button_pressed = get_press_state();
  button_long_pressed = get_long_press();
  button_double_pressed = get_double_press();

  encoder_val = get_encoder_val();

  // hanlde everthing periodically
  switch (main_state) {
    case DMX_PAGE:
      dmx_val.hanlde_dmx();
      switch (dmx_val.get_current()) {
        case WIRE:
          break;
        case SENDER:
          break;
        case RECEIVER:
          break;
      }
      rgb_out(dmx_val.get_dmx_message(), 255);
      break;
  }

  // cycle through display options
  if (button_pressed) {
    switch (main_state) {
      case HSV_PAGE:
        hsv_val.next();
        break;
      case RGB_PAGE:
        rgb_val.next();
        break;
      case DMX_PAGE:
        dmx_val.next();
        break;
      case PDC_PAGE:
        pdc.next();
        break;
      default:
        break;
    }
    set_press_state(false);
  }

  // cycle through the main menu
  if (button_long_pressed) {
    main_sw.next();
    set_long_press(false);
  }

  // save variables to EEPROM and display for two secconds
  // that the values has been saved
  if (button_double_pressed) {
    write_eeprom(hsv_val, rgb_val, dmx_val, pdc, main_sw);
    set_double_press(false);
    display_saved = true;
    display_saved_status(display);
    saved_timer_start = millis();
  }

  // display for two secconds that the data has been written to the eeprom
  if (millis() - saved_timer_start >= display_saved_time) {
    if (display_saved) {
      change_vals = true;
      display_saved = false;
    }
  }

  main_state = main_sw.get_current();

  // handle everything on event
  if (change_vals) {
    switch (main_state) {
      case HSV_PAGE:
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
      case RGB_PAGE:
        switch (rgb_val.get_current()) {
          case RED:
            rgb_val.add_red(encoder_val);
            break;
          case GREEN:
            rgb_val.add_green(encoder_val);
            break;
          case BLUE:
            rgb_val.add_blue(encoder_val);
            break;
        }
        rgb_out(rgb_val.get_rgb(), 255);
        rgb_display_update(display, rgb_val);
        break;
      case DMX_PAGE:
        switch (dmx_val.get_current()) {
          case WIRE:
            break;
          case SENDER:
            break;
          case RECEIVER:
            break;
        }
        dmx_val.add_to_adress(encoder_val);
        dmx_display_update(display, dmx_val);
        break;
      case PDC_PAGE:
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
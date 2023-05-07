#include "leds.h"

void init_led() {
  ledcSetup(RED_CHANNEL, PWM_FREQ, RESOLUTION);
  ledcSetup(GREEN_CHANNEL, PWM_FREQ, RESOLUTION);
  ledcSetup(BLUE_CHANNEL, PWM_FREQ, RESOLUTION);
  ledcAttachPin(RED_PIN, RED_CHANNEL);
  ledcAttachPin(GREEN_PIN, GREEN_CHANNEL);
  ledcAttachPin(BLUE_PIN, BLUE_CHANNEL);
}

void ramp_up(C_HSV led_val, pdc_page& pdc, main& main_sw) {
  uint16_t start_up_time = 1500;
  uint16_t t_delay = 0;
  uint8_t temp_brightness = 0;
  uint8_t temp_v = 0;
  
  switch (main_sw.get_current()) {
    case HSV:
      temp_v = led_val.get_val_p();
      t_delay = start_up_time / temp_v;
      for (int i = 0; i <= temp_v; i++) {
        led_val.set_val_p(i);
        hsv_out(led_val);
        delay(t_delay);
      }
      break;
    case PDC:
      temp_brightness = pdc.get_bright();
      t_delay = start_up_time / temp_brightness;
      for (int i = 0; i <= temp_brightness; i++) {
        pdc.set_bright(i);
        rgb_out(pdc.get_current_color(), pdc.get_bright());
        delay(t_delay);
      }
      break;
    default:
      delay(start_up_time);
      break;
  }
}

void rgb_out(CRGB led_val, uint8_t factor) {
  led_val.nscale8_video(factor);
  ledcWrite(RED_CHANNEL, led_val.r);
  ledcWrite(GREEN_CHANNEL, led_val.g);
  ledcWrite(BLUE_CHANNEL, led_val.b);
}

void hsv_out(C_HSV hsv_val) {
  uint8_t hue = hsv_val.get_hue();
  uint8_t sat = map(hsv_val.get_sat_p(), 0, 100, 0, 255);
  uint8_t val = map(hsv_val.get_val_p(), 0, 100, 0, 255);
  CHSV temp_hsv(hue, sat, val);
  CRGB temp_rgb;
  hsv2rgb_rainbow(temp_hsv, temp_rgb);
  rgb_out(temp_rgb, 255);
}
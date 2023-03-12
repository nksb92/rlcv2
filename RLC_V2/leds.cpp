#include "esp32-hal-gpio.h"
#include "esp32-hal.h"
#include "leds.h"

void init_led() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void rgb_out(CRGB led_val) {
  analogWrite(RED_PIN, led_val.r);
  analogWrite(GREEN_PIN, led_val.g);
  analogWrite(BLUE_PIN, led_val.b);
}

void hsv_out(C_HSV hsv_val){
  uint8_t hue = hsv_val.get_hue();
  uint8_t sat = map(hsv_val.get_sat_p(), 0, 100, 0, 255);
  uint8_t val = map(hsv_val.get_val_p(), 0, 100, 0, 255);
  CHSV temp_hsv(hue, sat, val);
  CRGB temp_rgb;
  hsv2rgb_rainbow(temp_hsv,temp_rgb);
  rgb_out(temp_rgb);
}
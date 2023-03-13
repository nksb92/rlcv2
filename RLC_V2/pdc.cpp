#include "pdc.h"

pdc_page::pdc_page(uint8_t crnt)
  : pdc_names({
    "WHITE",
    "WHITE-2",
    "CYAN",
    "PINK",
    "GREEN",
    "PINK-2",
    "ORANGE",
    "BLUE",
    "PURPLE",
    "LIME",
  }),
    predefined_colors({
      white_color,
      warm_white,
      cyan,
      pink,
      green,
      pink_two,
      orange,
      blue,
      purple,
      lime,
    }) {
  white_color.setRGB(255, 200, 190);
  warm_white.setRGB(255, 138, 18);
  cyan.setRGB(0, 255, 190);
  pink.setRGB(255, 0, 65);
  green.setRGB(0, 255, 0);
  pink_two.setRGB(255, 0, 255);
  orange.setRGB(255, 175, 0);
  blue.setRGB(0, 80, 255);
  purple.setRGB(120, 0, 255);
  lime.setRGB(136, 255, 0);
  current = crnt;
}

void pdc_page::set_current(uint8_t crnt) {
  current = crnt;
}

void pdc_page::next() {
  current++;
  if (current >= pdc_nmbr) {
    set_current(0);
  }
}

CRGB pdc_page::get_current_color() {
  return predefined_colors[current];
}

char* pdc_page::get_current_name() {
  return pdc_names[current];
}

void pdc_page::add_bright(int val) {
  if (brightness_p + val >= 100) {
    brightness_p = 100;
  } else if (brightness_p + val <= 0) {
    brightness_p = 0;
  } else {
    brightness_p += val;
  }
}

uint8_t pdc_page::get_bright() {
  return brightness_p;
}
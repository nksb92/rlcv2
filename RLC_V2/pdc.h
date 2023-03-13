#ifndef PDC_H
#define PDC_H

#include "common.h"

class pdc_page {
  uint8_t current = 0;
  uint8_t brightness_p = 75;
  static const uint8_t pdc_nmbr = 10;
  CRGB white_color;
  CRGB warm_white;
  CRGB cyan;
  CRGB pink;
  CRGB green;
  CRGB pink_two;
  CRGB orange;
  CRGB blue;
  CRGB purple;
  CRGB lime;
  char* pdc_names[pdc_nmbr];
  CRGB predefined_colors[pdc_nmbr];

public:
  pdc_page(uint8_t crnt);
  void set_current(uint8_t crnt) ;
  void next();
  CRGB get_current_color();
  char* get_current_name();
  void add_bright(int val);
  uint8_t get_bright();
};
#endif
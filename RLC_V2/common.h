#ifndef COMMON_H
#define COMMON_H

#include <Arduino.h>
#include <FastLED.h>

enum {
  HUE,
  SAT,
  VAL,
  HSV_LAST
};

class C_HSV {
  uint8_t hue;    // value between 0 and 255 (hue in 360/255 steps)
  uint8_t sat_p;  // value between 0 and 100 (saturation in percentage)
  uint8_t val_p;  // value between 0 and 100 (value in percentage)
  uint8_t current = HUE;
public:
  C_HSV(uint8_t _hue, uint8_t _sat_p, uint8_t _val_p) {
    hue = _hue;
    sat_p = _sat_p;
    val_p = _val_p;
  }
  void add_hue(int amount) {
    hue += amount;
  }
  void add_sat(int amount) {
    if (sat_p + amount > 100) sat_p = 100;
    else if (sat_p + amount <= 0) sat_p = 0;
    else sat_p += amount;
  }
  void add_val(int amount) {
    if (val_p + amount > 100) val_p = 100;
    else if (val_p + amount <= 0) val_p = 0;
    else val_p += amount;
  }
  uint8_t get_hue() {
    return hue;
  }
  uint8_t get_sat_p() {
    return sat_p;
  }
  uint8_t get_val_p() {
    return val_p;
  }
  void set_val_p(uint8_t value) {
    val_p = 0;
    add_val(value);
  }

  uint8_t get_current() {
    return current;
  }
  void set_hue() {
    current = HUE;
  }
  void set_sat() {
    current = SAT;
  }
  void set_val() {
    current = VAL;
  }
  void next() {
    current++;
    if (current >= HSV_LAST) {
      set_hue();
    }
  }
};

enum {
  HSV,
  DMX,
  PDC,
  MAIN_LAST
};

class main {
  uint8_t current = HSV;

public:
  uint8_t get_current() {
    return current;
  }
  void set_hsv() {
    current = HSV;
  }
  void next() {
    current++;
    if (current >= MAIN_LAST) {
      set_hsv();
    }
  }
};
#endif
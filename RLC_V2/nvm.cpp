#include "nvm.h"

void init_eeprom() {
  EEPROM.begin(EEPROM_ADDRESSES);
}

void read_eeprom(C_HSV& hsv_val, C_RGB& rgb_val, rgb_dmx& dmx_val, pdc_page& pdc, main& main_sw) {
  uint16_t eeprom_address = 0;

  // get all variables from the hsv page
  uint8_t hue = STD_HUE;
  EEPROM.get(eeprom_address, hue);
  hsv_val.set_hue_byte(hue);

  eeprom_address += sizeof(hue);

  uint8_t sat_p = STD_SAT_P;
  EEPROM.get(eeprom_address, sat_p);
  hsv_val.set_sat_p(sat_p);

  eeprom_address += sizeof(sat_p);

  uint8_t val_p = STD_VAL_P;
  EEPROM.get(eeprom_address, val_p);
  hsv_val.set_val_p(val_p);

  eeprom_address += sizeof(sat_p);

  // get all variables from the rgb page
  uint8_t red = STD_RED;
  EEPROM.get(eeprom_address, red);
  rgb_val.set_red(red);

  eeprom_address += sizeof(red);

  uint8_t green = STD_GREEN;
  EEPROM.get(eeprom_address, green);
  rgb_val.set_green(green);

  eeprom_address += sizeof(green);

  uint8_t blue = STD_BLUE;
  EEPROM.get(eeprom_address, blue);
  rgb_val.set_blue(blue);

  eeprom_address += sizeof(blue);

  // get all variables from the dmx page
  uint8_t current_dmx = STD_CURRENT;
  EEPROM.get(eeprom_address, current_dmx);
  dmx_val.set_current(current_dmx);

  eeprom_address += sizeof(current_dmx);

  uint16_t start_address = STD_START_ADDRESS;
  EEPROM.get(eeprom_address, start_address);
  dmx_val.set_start_address(start_address);

  eeprom_address += sizeof(start_address);

  // get all variables from the pre defined color page
  uint8_t current_pdc = STD_CURRENT;
  EEPROM.get(eeprom_address, current_pdc);
  pdc.set_current(current_pdc);

  eeprom_address += sizeof(current_pdc);

  uint8_t brightness_p = STD_BRIGHTNESS_PDC;
  EEPROM.get(eeprom_address, brightness_p);
  pdc.set_bright(brightness_p);

  eeprom_address += sizeof(brightness_p);

  // get the current main state
  uint8_t current_main = STD_CURRENT;
  EEPROM.get(eeprom_address, current_main);
  main_sw.set_current(current_main);
}

void write_eeprom(C_HSV& hsv_val, C_RGB& rgb_val, rgb_dmx& dmx_val, pdc_page& pdc, main& main_sw) {
  uint16_t eeprom_address = 0;

  // set all variables from the hsv page
  uint8_t hue = hsv_val.get_hue();
  EEPROM.put(eeprom_address, hue);

  eeprom_address += sizeof(hue);

  uint8_t sat_p = hsv_val.get_sat_p();
  EEPROM.put(eeprom_address, sat_p);

  eeprom_address += sizeof(sat_p);

  uint8_t val_p = hsv_val.get_val_p();
  EEPROM.put(eeprom_address, val_p);

  eeprom_address += sizeof(sat_p);

  // set all variables from the rgb page
  uint8_t red = rgb_val.get_red();
  EEPROM.put(eeprom_address, red);

  eeprom_address += sizeof(red);

  uint8_t green = rgb_val.get_green();
  EEPROM.put(eeprom_address, green);

  eeprom_address += sizeof(green);

  uint8_t blue = rgb_val.get_blue();
  EEPROM.put(eeprom_address, blue);

  eeprom_address += sizeof(blue);

  // set all variables from the dmx page
  uint8_t current_dmx = dmx_val.get_current();
  EEPROM.put(eeprom_address, current_dmx);

  eeprom_address += sizeof(current_dmx);

  uint16_t start_address = dmx_val.get_start();
  EEPROM.put(eeprom_address, start_address);

  eeprom_address += sizeof(start_address);

  // set all variables from the pre defined color page
  uint8_t current_pdc = pdc.get_current();
  EEPROM.put(eeprom_address, current_pdc);

  eeprom_address += sizeof(current_pdc);

  uint8_t brightness_p = pdc.get_bright();
  EEPROM.put(eeprom_address, brightness_p);

  eeprom_address += sizeof(brightness_p);

  // set the current main state
  uint8_t current_main = main_sw.get_current();
  EEPROM.put(eeprom_address, current_main);
  EEPROM.commit();
}
#include "nvm.h"

void init_eeprom() {
  EEPROM.begin(EEPROM_ADDRESSES);
}

void read_eeprom(C_HSV& hsv_val, rgb_dmx& dmx_val) {
  uint16_t eeprom_address = 0;

  uint8_t hue;
  EEPROM.get(eeprom_address, hue);
  hsv_val.set_hue_byte(hue);

  eeprom_address += sizeof(hue);

  uint8_t sat_p;
  EEPROM.get(eeprom_address, sat_p);
  hsv_val.set_sat_p(sat_p);

  eeprom_address += sizeof(sat_p);

  uint8_t val_p;
  EEPROM.get(eeprom_address, val_p);
  hsv_val.set_val_p(val_p);

  eeprom_address += sizeof(sat_p);
  // hue, sat val in percentage (hsv) done

  uint8_t current_dmx;

  // current, start_address (dmx) done

  // current, brightness_p (pdc) done

  // current (main) done
}

uint16_t save_var(uint16_t address, int variable) {
  EEPROM.put(address, variable);
  return address + sizeof(variable);
}

void write_eeprom() {}
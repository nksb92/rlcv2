#include "nvm.h"

void init_eeprom(){
    EEPROM.begin(EEPROM_ADDRESSES);
}

void read_eeprom() {
  uint16_t eeprom_address = 0;

  uint8_t hue;
  EEPROM.get(eeprom_address, hue);
  hsv_val.set_hue_byte(hue);

  eeprom_address += sizeof(hue);

  uint8_t sat_p;
  EEPROM.get(eeprom_address, sat_p);
  hsv_val.set_sat_p(sat_p);
  // hue, sat val in percentage (hsv) done

  // current, start_address (dmx) done

  // current, brightness_p (pdc) done

  // current (main) done
}

void write_eeprom() {}
#ifndef NVM_H
#define NVM_H

#include "common.h"
#include "dmx.h"
#include <EEPROM.h>

#define EEPROM_ADDRESSES 512

void init_eeprom();

void read_eeprom(C_HSV& hsv_val, rgb_dmx& dmx_val);

void write_eeprom();

#endif
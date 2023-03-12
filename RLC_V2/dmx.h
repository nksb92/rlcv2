#ifndef DMX_H
#define DMX_H

// https://github.com/someweisguy/esp_dmx
#include <esp_dmx.h>
#include "common.h"

class rgb_dmx {
  volatile uint16_t start_address = 1;
  const uint8_t used_addresses = 4;
  volatile uint16_t last_address = 512 - used_addresses + 1;
  CRGB dmx_message;
  dmx_port_t dmxPort = 0;
  byte data[DMX_PACKET_SIZE];

public:
  rgb_dmx(CRGB init_rgb);
  void install_dmx();
  void hanlde_dmx();
  void add_to_adress(int value);
  uint16_t get_start();
  uint8_t get_used_nbr();
  CRGB get_dmx_message();
};
#endif
#ifndef DMX_H
#define DMX_H

// https://github.com/someweisguy/esp_dmx
#include <esp_dmx.h>
#include "common.h"
enum {
  WIRE,
  MASTER,
  MESH,
  DMX_LAST
};

class rgb_dmx {
  volatile uint8_t current = 0;
  volatile uint16_t start_address = 1;
  const uint8_t used_addresses = 4;
  volatile uint16_t last_address = 512 - used_addresses + 1;
  
  CRGB dmx_message;
  uint8_t dim = 0;

  dmx_port_t dmxPort = 0;
  uint8_t data[DMX_PACKET_SIZE];
  char* modes[DMX_LAST];

public:
  rgb_dmx(CRGB init_rgb);
  uint8_t get_current();
  void set_current(uint8_t val);
  void next();
  char* get_current_txt();
  void install_dmx();
  void set_rgb(uint8_t _data[]);
  void hanlde_dmx();
  void add_to_adress(int value);
  uint16_t get_start();
  uint8_t get_used_nbr();
  CRGB get_dmx_message();
  void set_data(uint8_t information, uint16_t index);
  uint8_t get_data(uint16_t index);
};
#endif
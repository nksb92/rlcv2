#ifndef DMX_H
#define DMX_H

// https://github.com/someweisguy/esp_dmx
#include <esp_dmx.h>
#include "common.h"
<<<<<<< Updated upstream
=======

enum {
  WIRE,
  MASTER,
  MESH,
  DMX_LAST
};
>>>>>>> Stashed changes

// class to handle dmx messages
class rgb_dmx {
<<<<<<< Updated upstream
  volatile uint16_t start_address = 1;
  const uint8_t used_addresses = 4;
  volatile uint16_t last_address = 512 - used_addresses + 1;
  CRGB dmx_message;
  dmx_port_t dmxPort = 0;
  byte data[DMX_PACKET_SIZE];
=======
  volatile uint8_t current = 0;                               // The current menu index
  volatile uint16_t start_address = 1;                        // The current start address
  const uint8_t used_addresses = 4;                           // The amount of used addresses -> Red, Green, Blue, Dimming
  volatile uint16_t last_address = 512 - used_addresses + 1;  // The last possible address

  CRGB dmx_message;  // Variable to store the color
  uint8_t dim = 0;   // Dimming factor given with the fouth address

  dmx_port_t dmxPort = 0;         // Dmx port for the esp_dmx libarary
  uint8_t data[DMX_PACKET_SIZE];  // Array to receive the dmx data in
  char* modes[DMX_LAST];          // Array to store the names of the pages
>>>>>>> Stashed changes

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
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

// class to handle dmx messages
class rgb_dmx {
  volatile uint8_t current = 0;                               // The current menu index
  volatile uint16_t start_address = 1;                        // The current start address
  const uint8_t used_addresses = 4;                           // The amount of used addresses -> Red, Green, Blue, Dimming
  volatile uint16_t last_address = 512 - used_addresses + 1;  // The last possible address

  CRGB dmx_message;  // Variable to store the color
  uint8_t dim = 0;   // Dimming factor given with the fouth address

  dmx_port_t dmxPort = 0;         // Dmx port for the esp_dmx libarary
  uint8_t data[DMX_PACKET_SIZE];  // Array to receive the dmx data in
  char* modes[DMX_LAST];          // Array to store the names of the pages

public:
  /*
  Constructor of the class rgb_dmx
  @param init_rgb: variable to set the default value of the dmx_message
  */
  rgb_dmx(CRGB init_rgb);
  
  /*
  Returns the value of the variable current
  */
  uint8_t get_current();
  
  /*
  Adds one to current and keeps it inside the possible values 
  */
  void next();
  
  /*
  Returns the current page name
  */
  char* get_current_txt();
  
  /*
  Init of the dmx, needs to be called in Setup
  */
  void install_dmx();
  
  /*
  Returns the current start address
  */
  uint16_t get_start();
  
  /*
  Returns the amount of addresses needed for dmx
  */
  uint8_t get_used_nbr();
  
  /*
  Adds the given value to the start_address value,
  if value is smaller than 1 it will be set to the highest possible value,
  if value is bigger than the highest possible value it will be set to 1
  @param value: integer value to be added (positive or negative)
  */
  void add_to_adress(int value);  
  
  /*
  Handles the incoming dmx messages either over wire or from Wlan mesh  
  */
  void hanlde_dmx();  

  /*
  Returns the current dmx_messeage (values of the red, green and blue channel)
  */
  CRGB get_dmx_message();

  /*
  Sets the data array at the given index to the given information
  @param information: value between 0 and 255 to be stored at the index
  @param index: index where to store the information, value between 0 and 512
  */
  void set_data(uint8_t information, uint16_t index);

  /*
  Returns the current information stored at the given index
  */
  uint8_t get_data(uint16_t index);
};
#endif
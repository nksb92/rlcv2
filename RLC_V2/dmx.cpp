#include "dmx.h"

/*
Pins for the communication with the RS-485 IC
@param TRANSMIT_PIN: pin for sending data
@param RECEIVE_PIN: pin for receiving data
@param ENABLE_PIN: pin to pull RS-485 IC high or low; high for sending data, low for receiving data
*/
#define TRANSMIT_PIN 21 
#define RECEIVE_PIN 20
#define ENABLE_PIN 5

<<<<<<< Updated upstream
rgb_dmx::rgb_dmx(CRGB init_rgb) {
=======
/*
Constructor of the class rgb_dmx
@param init_rgb: variable to set the default value of the dmx_message
*/
rgb_dmx::rgb_dmx(CRGB init_rgb)
  : modes({ "Wire", "Main", "Mesh" }) {
>>>>>>> Stashed changes
  dmx_set_pin(dmxPort, TRANSMIT_PIN, RECEIVE_PIN, ENABLE_PIN);
  dmx_message = init_rgb;
}

<<<<<<< Updated upstream
=======
/*
Returns the value of the variable current
*/
uint8_t rgb_dmx::get_current() {
  return current;
}

/*
Adds one to current and keeps it inside the possible values 
*/
void rgb_dmx::next() {
  current++;
  if (current >= DMX_LAST) {
    current = 0;
  }
}

/*
Returns the current page name
*/
char* rgb_dmx::get_current_txt() {
  return modes[current];
}

/*
Init of the dmx, needs to be called in Setup
*/
>>>>>>> Stashed changes
void rgb_dmx::install_dmx() {
  dmx_driver_install(dmxPort, DMX_DEFAULT_INTR_FLAGS);
}

/*
Returns the current start address
*/
uint16_t rgb_dmx::get_start() {
  return start_address;
}
<<<<<<< Updated upstream
uint8_t rgb_dmx::get_used_nbr() {
  return used_addresses;
}
=======

/*
Returns the amount of addresses needed for dmx
*/
uint8_t rgb_dmx::get_used_nbr() {
  return used_addresses;
}

/*
Adds the given value to the start_address value,
if value is smaller than 1 it will be set to the highest possible value,
if value is bigger than the highest possible value it will be set to 1
@param value: integer value to be added (positive or negative)
*/
>>>>>>> Stashed changes
void rgb_dmx::add_to_adress(int value) {
  int temp = start_address + value;
  if (temp > last_address) {
    start_address = 0;
  } else if (temp < 0) {
    start_address = last_address;
  } else {
    start_address = temp;
  }
}

void rgb_dmx::hanlde_dmx() {
  dmx_packet_t packet;
  if (dmx_receive(dmxPort, &packet, DMX_TIMEOUT_TICK)) {
    if (!packet.err) {
      dmx_read(dmxPort, data, packet.size);
      dmx_message.r = data[start_address + 0];
      dmx_message.g = data[start_address + 1];
      dmx_message.b = data[start_address + 2];
      uint8_t factor = data[start_address + 3];  // dimming factor
      dmx_message.nscale8(factor);
    }
  }
}

/*
Returns the current dmx_messeage (values of the red, green and blue channel)
*/
CRGB rgb_dmx::get_dmx_message() {
  return dmx_message;
}
<<<<<<< Updated upstream
=======

/*
Sets the data array at the given index to the given information
@param information: value between 0 and 255 to be stored at the index
@param index: index where to store the information, value between 0 and 512
*/
void rgb_dmx::set_data(uint8_t information, uint16_t index) {
  data[index] = information;
}

/*
Returns the current information stored at the given index
*/
uint8_t rgb_dmx::get_data(uint16_t index) {
  return data[index];
}
>>>>>>> Stashed changes

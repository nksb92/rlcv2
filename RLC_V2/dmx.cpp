#include "dmx.h"

#define TRANSMIT_PIN 21
#define RECEIVE_PIN 20
#define ENABLE_PIN 5

rgb_dmx::rgb_dmx(CRGB init_rgb) {
  dmx_set_pin(dmxPort, TRANSMIT_PIN, RECEIVE_PIN, ENABLE_PIN);
  dmx_message = init_rgb;
}

void rgb_dmx::install_dmx() {
  dmx_driver_install(dmxPort, DMX_DEFAULT_INTR_FLAGS);
}

uint16_t rgb_dmx::get_start() {
  return start_address;
}
uint8_t rgb_dmx::get_used_nbr() {
  return used_addresses;
}
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

CRGB rgb_dmx::get_dmx_message() {
  return dmx_message;
}

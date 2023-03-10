#include "dmx.h"

#define START_CHANNEL 1
#define TOTAL_CHANNEL 3

#define TRANSMIT_PIN 21
#define RECEIVE_PIN 20
#define ENABLE_PIN 5

rgb_dmx::rgb_dmx(CRGB init_rgb) {
  dmx_set_pin(dmxPort, TRANSMIT_PIN, RECEIVE_PIN, ENABLE_PIN);
  dmx_driver_install(dmxPort, DMX_DEFAULT_INTR_FLAGS);
  dmx_message = init_rgb;
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
      for (uint16_t i = start_address; i < start_address + used_addresses - 1; i++) {
        dmx_message[i] = data[start_address + i];  // save rgb values
      }
      uint8_t factor = data[start_address + used_addresses];  // dimming factor
      dmx_message.nscale8(factor);
    } else {
    }
  }
}

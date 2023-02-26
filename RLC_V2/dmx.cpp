#include "dmx.h"

#define START_CHANNEL 1
#define TOTAL_CHANNEL 3

#define TRANSMIT_PIN 21
#define RECEIVE_PIN 20
#define ENABLE_PIN 5

dmx_port_t dmxPort = 0;
byte data[DMX_PACKET_SIZE];

void init_dmx() {
  dmx_set_pin(dmxPort, TRANSMIT_PIN, RECEIVE_PIN, ENABLE_PIN);
  dmx_driver_install(dmxPort, DMX_DEFAULT_INTR_FLAGS);
}

void hanlde_dmx(CRGB& val) {
  dmx_packet_t packet;
  if (dmx_receive(dmxPort, &packet, DMX_TIMEOUT_TICK)) {
    if (!packet.err) {
      dmx_read(dmxPort, data, packet.size);

      val[0] = data[START_CHANNEL];      // red channel
      val[1] = data[START_CHANNEL + 1];  // green channel
      val[2] = data[START_CHANNEL + 2];  // blue channel
    } else {
      val[0] = 0;  // red channel
      val[1] = 0;  // green channel
      val[2] = 0;  // blue channel
    }
  }
}
#include "wlan_mesh.h"

// The data buffer for DMX packets
uint8_t data[DMX_PACKET_SIZE];

void init_mesh(painlessMesh& _mesh) {
  _mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT);
  _mesh.onReceive(&receive_message);
}

void send_message(painlessMesh& _mesh, rgb_dmx& dmx_mess) {
  JSONVar out_message;
  for (uint16_t i = 0; i < DMX_PACKET_SIZE; i++) {
    out_message[i] = dmx_mess.get_data(i);
  }
  String temp = JSON.stringify(out_message);
  _mesh.sendBroadcast(temp);
}

void receive_message(uint32_t from, String& msg) {
  JSONVar in_message = JSON.parse(msg.c_str());
  Serial.println(in_message);
  for (uint16_t i = 0; i < DMX_PACKET_SIZE; i++) {
    data[i] = in_message[i];
  }
}

uint8_t get_data(uint16_t index){
  return data[index];
}
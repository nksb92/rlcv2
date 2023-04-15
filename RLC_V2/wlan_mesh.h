#ifndef WLAN_MESH_H
#define WLAN_HESH_H

#include "common.h"
#include <painlessMesh.h>
#include <Arduino_JSON.h>
#include "dmx.h"

#define MESH_PREFIX "RLCV2"
#define MESH_PASSWORD "GTZytYQ_3c__PBCCZ4T3XA"
#define MESH_PORT 5555

// remember to put the mesh.update function in the loop#

void init_mesh(painlessMesh& _mesh);

void send_message(painlessMesh& _mesh, rgb_dmx& dmx_mess);

void receive_message(uint32_t from, String& msg);

uint8_t get_data(uint16_t index);
#endif
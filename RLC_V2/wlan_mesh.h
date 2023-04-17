#ifndef WLAN_MESH_H
#define WLAN_HESH_H

#include "common.h"
#include <painlessMesh.h>
#include <Arduino_JSON.h>
#include "dmx.h"

// The prefix for the mesh network SSID:
#define MESH_PREFIX "RLCV2"

// The password for the mesh network:
#define MESH_PASSWORD "GTZytYQ_3c__PBCCZ4T3XA"

// The port to use for mesh network communication:
#define MESH_PORT 5555

/**
 * Initializes the mesh network with the specified settings and message handler
 *
 * @param _mesh: The painlessMesh instance to initialize
 */
void init_mesh(painlessMesh& _mesh);

/**
 * Sends a DMX message over the mesh network
 *
 * @param _mesh: The painlessMesh instance to use for sending the message
 * @param dmx_mess: The RGB DMX message to send
 */
void send_message(painlessMesh& _mesh, rgb_dmx& dmx_mess);

/**
 * Handles an incoming message received over the mesh network
 *
 * @param from: The ID of the node that sent the message
 * @param msg: The message data
 */
void receive_message(uint32_t from, String& msg);

/**
 * Gets the value of a byte in the DMX data buffer
 *
 * @param index: The index of the byte to get
 * @return: The value of the byte at the specified index
 */
uint8_t get_data(uint16_t index);

#endif 
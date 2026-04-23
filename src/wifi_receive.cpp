#include "ArduinoLinkPLC.h"

char incomingPacket[255];

void receive_packets() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    int len = udp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = 0;
    }

    String msg = String(incomingPacket);

    parsePacketMessage(msg);
  }
}

void parsePacketMessage(String msg) {
  if (msg.indexOf("START_RACE") >= 0) {
    // enable detection
  }
  else if (msg.indexOf("RESET") >= 0) {
    // reset state
  }
  else if (msg.indexOf("SET_LED") >= 0) {
    digitalWrite(2, HIGH);
  }
}
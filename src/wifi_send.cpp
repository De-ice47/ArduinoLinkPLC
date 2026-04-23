#include "ArduinoLinkPLC.h"

void send_packet(String msg)
{
    udp.beginPacket(masterComputerIP, masterComputerPort);
    udp.print(msg);
    udp.endPacket();
}
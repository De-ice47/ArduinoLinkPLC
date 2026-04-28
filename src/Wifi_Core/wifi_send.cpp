#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    void send_packet(const char* type,const char* dataJSON)
    {
        Packet packet = ArduinoLinkPLC::constructPacket(type,dataJSON,"UnityLink");
        udp.beginPacket(masterComputerIP, masterComputerPort);
        udp.print(dataJSON);
        udp.endPacket();
        Serial.println("[Wifi] (" + String(type) + ") " + String(dataJSON));
    }
}
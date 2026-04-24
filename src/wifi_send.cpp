#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    void send_packet(String msg)
    {
        udp.beginPacket(masterComputerIP, masterComputerPort);
        udp.print(msg);
        udp.endPacket();
    }
}
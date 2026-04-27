#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    void send_packet(char* type,char* dataJSON)
    {
        Packet packet = constructPacket(dataJSON,type,"UnityLink");
        udp.beginPacket(masterComputerIP, masterComputerPort);
        udp.print(dataJSON);
        udp.endPacket();
    }
}
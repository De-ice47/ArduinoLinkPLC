#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
  char incomingPacket[255];
  ArduinoLinkPLC::EventString onPacketReceived;

  void receive_packets()
  {
    int packetSize = udp.parsePacket();
    if (packetSize)
    {
      int len = udp.read(incomingPacket, 255);
      if (len > 0)
      {
        incomingPacket[len] = 0;
      }

      const char* msg = incomingPacket;
      onPacketReceived.invoke(msg);
      ArduinoLinkPLC::deconstructPacket(msg);
    }
  }
}
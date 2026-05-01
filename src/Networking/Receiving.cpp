#include "internal/VeloxityLink_Internal.h"
namespace VeloxityLink
{
  char incomingPacket[255];
  VeloxityLink::EventString onPacketReceived;

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

      const char *msg = incomingPacket;
      
      Packet packet = VeloxityLink::deconstructPacket(msg);
      onPacketReceived.invoke(packet);
          
      if (showSerialOutput)
        Serial.println("[Wifi-R] (" + String(packet.SenderID) + ") <" + String(packet.Type) + ">" + String(packet.DataJSON));
      VeloxityLink::React(packet); // This broadcast is for this device only
    }
  }
}
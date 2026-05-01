#include "internal/ArduinoLinkPLC_Internal.h"
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

      const char *msg = incomingPacket;
      onPacketReceived.invoke(msg);

      Packet packet = ArduinoLinkPLC::deconstructPacket(msg);
          
      if (showSerialOutput)
        Serial.println("[Wifi-R] (" + String(packet.SenderID) + ") <" + String(packet.Type) + ">" + String(packet.DataJSON));
      ArduinoLinkPLC::React(packet); // This broadcast is for this device only
    }
  }
}
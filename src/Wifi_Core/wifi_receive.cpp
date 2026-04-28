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

      const char *msg = incomingPacket;
      onPacketReceived.invoke(msg);

      Packet packet = ArduinoLinkPLC::deconstructPacket(msg);
      bool globalBroadcast = strcmp(packet.ReceiverID, "") == 0;
      if (globalBroadcast) // This broadcast is a global one for this device
      {
        if(showSerialOutput) Serial.println("[Wifi-R] ("+String(packet.SenderID)+") => (Global Broadcast) <"+ String(packet.Type) +"> : " + String(packet.DataJSON));
        ArduinoLinkPLC::React(packet);
      }
      else
      {
        if (strcmp(packet.ReceiverID, DeviceID) != 0)
          return; // This broadcast is not for this device
        else
        {
          if(showSerialOutput) Serial.println("[Wifi-R] ("+String(packet.SenderID)+") => (" + String(packet.ReceiverID) + ") ("+ String(packet.Type) +")" + String(packet.DataJSON));
          ArduinoLinkPLC::React(packet);
        }
      }
    }
  }
}
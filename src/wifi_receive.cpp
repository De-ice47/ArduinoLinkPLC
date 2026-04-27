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
      Packet packet = ArduinoLinkPLC::deconstructPacket(msg);
      // Reaction code (Send to its own file)
      char* dataJSON;
      // Packet Processing
      if(strcmp(packet.Type,"PING") == 0){
        const char* dataJSON = "Here I am";
      }

      send_packet("PING",dataJSON);
    }
  }
}
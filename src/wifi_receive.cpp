#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
  char incomingPacket[255];
  ArduinoLinkPLC::EventString onPacketReceived;
  namespace
  {
    void parsePacketMessage(String msg);
  }

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

      String msg = String(incomingPacket);
      onPacketReceived.invoke(msg);
      parsePacketMessage(msg);
    }
  }
  namespace
  {
    void parsePacketMessage(String msg)
    {
      if (msg.indexOf("START_RACE") >= 0)
      {
        // enable detection
      }
      else if (msg.indexOf("RESET") >= 0)
      {
        // reset state
      }
      else if (msg.indexOf("SET_LED") >= 0)
      {
        digitalWrite(2, HIGH);
      }
    }
  }
}
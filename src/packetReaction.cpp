#include "internal/ArduinoLinkPLC_Internal.h"

namespace ArduinoLinkPLC
{
  void React(Packet packet)
  {
    char *dataJSON;
    // Packet Processing
    if (strcmp(packet.Type, "PING") == 0)
    {
      Ping(packet);
    }
  }
  void Ping(Packet packet)
  {
    String ipStr = localIP.toString();
    ArduinoLinkPLC::send_packet("PING", ipStr.c_str(),IPAddress(gateway[0], gateway[1], gateway[2], 255), packet.TimeStamp);
  }
}
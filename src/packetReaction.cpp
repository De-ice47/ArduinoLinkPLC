#include "internal/ArduinoLinkPLC_Internal.h"

namespace ArduinoLinkPLC
{
  void React(Packet packet)
  {
    char *dataJSON;
    // Packet Processing
    if (strcmp(packet.Type, "PING") == 0)
    {
      Ping();
    }
  }
  void Ping()
  {
    String ipStr = localIP.toString();
    ArduinoLinkPLC::send_packet("PING", ipStr.c_str());
  }
}
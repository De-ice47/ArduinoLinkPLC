#include "ArduinoLinkPLC_Internal.h"

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
    const char *dataJSON = ipStr.c_str();
    ArduinoLinkPLC::send_packet("PING", dataJSON);
  }
}
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
    char *dataJSON = "Here I am";
    ArduinoLinkPLC::send_packet("PING", dataJSON);
  }
}
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    // Main Runtime Functions
    void setup_library()
    {
        setup_wifi();
    }
    void loop_library()
    {
        receive_packets();
        wifi_checkStatus();
    }
}
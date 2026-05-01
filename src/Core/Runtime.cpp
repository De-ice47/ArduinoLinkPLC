#include "Internal/ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    void run_network()
    {
        receive_packets();
        wifi_checkStatus();
    }
}
#include "ArduinoLinkPLC.h"

namespace ArduinoLinkPLC
{
    // Variables

    extern WiFiUDP udp;

    // Functions

    void setup_wifi();
    void receive_packets();
    void wifi_checkStatus();
    void test_eventSystem();
}
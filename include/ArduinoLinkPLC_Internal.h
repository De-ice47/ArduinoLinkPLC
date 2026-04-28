#pragma once
#include "ArduinoLinkPLC.h"

// Things that are not exposed outside the library
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
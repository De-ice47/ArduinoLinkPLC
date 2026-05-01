// Things that are for in library use only, use with caution outside the library
#pragma once
#include "ArduinoLinkPLC.h"
// Seperate Divisions of the internals
#include "internal/EventString.h"
#include "internal/Networking.h"
#include "internal/Packet.h"
#include "internal/PacketConstruction.h"
#include "internal/PacketReaction.h"
namespace ArduinoLinkPLC
{
    // Runtime
    void setup_library();

    // Functions

    void setup_wifi();
    void receive_packets();
    void wifi_checkStatus();
    void test_eventSystem();
    void statusLight(bool);
}
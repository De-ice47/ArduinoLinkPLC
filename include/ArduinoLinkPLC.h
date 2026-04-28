#pragma once
#include "Core/ArduinoLinkPLC_Settings.h"
#include "Core/ArduinoLinkPLC_Classes.h"
#include "Core/ArduinoLinkPLC_Scripts.h"
namespace ArduinoLinkPLC
{
    // Global vars
    extern IPAddress masterComputerIP;
    extern const char *masterComputerSSID;
    extern const char *masterComputerSSIDPassword;
    extern const int masterComputerPort;

    // Master loop and setup functions
    void setup_library();
    void loop_library();

    // Sending
    void send_packet(const char *, const char *);
    // Receiving
    extern ArduinoLinkPLC::EventString onPacketReceived;
    //
    Packet constructPacket(const char *, const char *, const char *);
    Packet deconstructPacket(const char *);
}

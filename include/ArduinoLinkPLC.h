#pragma once
#include "Core/ArduinoLinkPLC_Settings.h"
#include "internal/EventString.h"
namespace ArduinoLinkPLC
{
    // Sending
    /**
     * @brief Sends a packet from this microcontroller
     * @param type The title of the packet. Good for identifying what a package is on the receiving end.
     * @param data The custom data sent in the packet.
     */
    void send_packet(const char *type, const char *data);
    /**
     * @brief Sends a packet from this microcontroller
     * @param type The title of the packet. Good for identifying what a package is on the receiving end.
     * @param data The custom data sent in the packet.
     * @param targetIP The target device for this packet.
     */
    void send_packet(const char *type, const char *data, IPAddress targetIP);
    // Receiving
    /**
     * @brief An event that triggers whenever a packet is received
     */
    extern ArduinoLinkPLC::EventString onPacketReceived;
    /**
     * @brief Starts the mircocontroller's connection to the network choosen.
     */
    void start_network();
    /**
     * @brief Stops the mircocontroller's connection to the network choosen.
     */
    void stop_network();
    /**
     * @brief Loops through the functions required to run the microcontroller's connection to the network.
     */
    void run_network();
}

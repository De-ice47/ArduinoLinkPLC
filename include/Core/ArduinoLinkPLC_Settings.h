#pragma once
#include "Core/ArduinoLinkPLC_Dependency.h"
namespace ArduinoLinkPLC
{
    // Device ID
    extern char *DeviceID;
    // Network Settings

    extern IPAddress localIP;
    extern IPAddress gateway;
    extern char *masterComputerSSID;
    extern char *masterComputerSSIDPassword;
    extern int masterComputerPort;
    extern bool showSerialOutput;
    extern bool useInternalLED;

    /**
     * @brief If this library can use the serial output to sent messages to connected devices
     */
    void displaySerialOutput(bool);
    /**
     * @brief If this library can use the built-in LED on the microcontroller to display WiFi status
     */
    void AllowInternalLEDUse(bool);
    // configuration functions
    /**
     * @brief Sets the IP address of the microcontroller on the network
     * @param local_IP The IP address
     */
    void setLocalIP(IPAddress local_IP);
    /**
     * @brief Sets the name of the microcontroller on the network
     * @param deviceID The name of the device
     */
    void setDeviceID(char *deviceID);
    /**
     * @brief Sets the gateway device IP address (The IP address of the router or hotspot hosting the network)
     * @param gatewayIP The IP address of the gateway device
     */
    void setGatewayIP(IPAddress gatewayIP);
    /**
     * @brief Sets the network that the microcontroller will connect to
     * @param SSID The name of the network
     */
    void setNetworkSSID(char *SSID);
    /**
     * @brief Sets the network that the microcontroller will connect to
     * @param SSID The name of the network
     * @param SSID_Password The password for that network
     */
    void setNetworkSSID(char *SSID, char *SSID_Password);
    /**
     * @brief Sets the port for the microcontroller's connection
     * @param port The port number for the microcontroller's connection
     */
    void setPort(int port);
}
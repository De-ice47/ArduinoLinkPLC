#include "ArduinoLinkPLC.h"
// Main Runtime Functions
void setup()
{
    setup_wifi();
}
void loop()
{
    receive_packets();
    wifi_checkStatus();
}
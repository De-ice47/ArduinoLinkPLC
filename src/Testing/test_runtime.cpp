#include "ArduinoLinkPLC.h";

void displayPacket(const String &msg){
    Serial.println("[Wifi] (Received) " + msg);
}

void setup(){
    Serial.begin(9600);
    ArduinoLinkPLC::onPacketReceived.subscribe(displayPacket);
    ArduinoLinkPLC::setup_library();
}
void loop(){
    ArduinoLinkPLC::loop_library();
}
#include "ArduinoLinkPLC.h";

void displayPacket(const char* &msg){
    //Serial.println("[Wifi] (Received) " + String(msg));
}

void setup(){
    Serial.begin(9600);
    ArduinoLinkPLC::onPacketReceived.subscribe(displayPacket);
    ArduinoLinkPLC::setup_library();
}
void loop(){
    ArduinoLinkPLC::loop_library();
}
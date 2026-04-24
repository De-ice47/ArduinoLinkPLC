#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
ArduinoLinkPLC::EventString onTestMessage;

void listener1(const String &msg)
{
    Serial.println("Listener1: " + msg);
}

void listener2(const String &msg)
{
    Serial.println("Listener2: " + msg);
}

void test_eventSystem()
{
    Serial.println("Event System Test...");
    onTestMessage.subscribe(listener1);
    onTestMessage.subscribe(listener2);

    onTestMessage.invoke("Hello World");
}
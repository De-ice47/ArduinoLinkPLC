#pragma once
#include "Core/ArduinoLinkPLC_Settings.h"

namespace ArduinoLinkPLC
{
    class Packet
    {
    public:
        const char *SenderID;
        long TimeStamp;
        const char *Type;
        const char *DataJSON;
        Packet(const char *type, const char *dataJSON)
        {
            SenderID = DeviceID;
            TimeStamp = 0;
            Type = type;
            DataJSON = dataJSON;
        };
        Packet()
        {
            SenderID = "";
            TimeStamp = 0;
            Type = "";
            DataJSON = "";
        };
    };
}
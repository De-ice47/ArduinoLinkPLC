#pragma once
#include "Core/ArduinoLinkPLC_Settings.h"

namespace ArduinoLinkPLC
{
    class Packet
    {
    public:
        const char *SenderID;
        const char *ReceiverID;
        long TimeStamp;
        const char *Type;
        const char *DataJSON;
        Packet(const char *type, const char *dataJSON, const char *ReceiverID)
        {
            SenderID = DeviceID;
            ReceiverID = ReceiverID;
            TimeStamp = 0;
            Type = type;
            DataJSON = dataJSON;
        };
        Packet()
        {
            SenderID = "";
            ReceiverID = "";
            TimeStamp = 0;
            Type = "";
            DataJSON = "";
        };
    };
}
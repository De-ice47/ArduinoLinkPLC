#pragma once
#include "ArduinoLinkPLC_Settings.h"
namespace ArduinoLinkPLC
{
    // Events
    typedef void (*EventCallback)(const char* &msg);
#define MAX_EVENT_LISTENERS 4
    // Classes
    class EventString
    {
    private:
        EventCallback listeners[MAX_EVENT_LISTENERS];
        int count = 0;

    public:
        void subscribe(EventCallback cb);
        void invoke(const char *&msg);
        void clear_all_listeners();
    };
    class Packet
    {
    public:
        const char *SenderID;
        const char *ReceiverID;
        long TimeStamp;
        const char *Type;
        const char *DataJSON;
        Packet(const char *ReceiverID, const char *type, char *dataJSON)
        {
            SenderID = deviceSenderID;
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
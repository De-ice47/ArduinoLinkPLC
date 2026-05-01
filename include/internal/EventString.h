#pragma once
#include "Core/ArduinoLinkPLC_Settings.h"
namespace ArduinoLinkPLC
{
    // Events
    typedef void (*EventCallback)(const char *&msg);
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
}
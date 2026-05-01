#pragma once
#include "Packet.h"
namespace VeloxityLink
{
    // Events
    typedef void (*EventCallback)(const Packet &msg);
#define MAX_EVENT_LISTENERS 4
    // Classes
    class EventString
    {
    private:
        EventCallback listeners[MAX_EVENT_LISTENERS];
        int count = 0;

    public:
        void subscribe(EventCallback cb);
        void invoke(const Packet &msg);
        void clear_all_listeners();
    };
}
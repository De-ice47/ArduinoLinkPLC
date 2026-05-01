#pragma once
#include "internal/EventString.h"
namespace VeloxityLink
{
    // Subscribe a listener
    void EventString::subscribe(EventCallback cb)
    {
        if (count < MAX_EVENT_LISTENERS)
        {
            listeners[count++] = cb;
        }
    }

    // Trigger the event
    void EventString::invoke(const Packet &msg)
    {
        for (int i = 0; i < count; i++)
        {
            if (listeners[i] != nullptr)
            {
                listeners[i](msg);
            }
        }
    }

    // Optional: clear all listeners
    void EventString::clear_all_listeners()
    {
        count = 0;
    }
};

#pragma once
#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
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
    void EventString::invoke(const char* &msg)
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

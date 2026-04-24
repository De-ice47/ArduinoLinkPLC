#include <Arduino.h>
namespace ArduinoLinkPLC
{
    // Events
    typedef void (*EventCallback)(const String &msg);
#define MAX_EVENT_LISTENERS 4
    // Classes
    class EventString
    {
    private:
        EventCallback listeners[MAX_EVENT_LISTENERS];
        int count = 0;

    public:
        void subscribe(EventCallback cb);
        void invoke(const String &msg);
        void clear_all_listeners();
    };
}
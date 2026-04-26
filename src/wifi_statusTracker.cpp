#include "ArduinoLinkPLC.h"
#include "ArduinoLinkPLC_Internal.h"
namespace ArduinoLinkPLC
{
    int lastStatus = -1;
    void wifi_checkStatus()
    {
        int currentStatus = WiFi.status();
        if (lastStatus != currentStatus)
        {
            lastStatus = currentStatus;
            switch (WiFi.status())
            {
            case WL_IDLE_STATUS:
                Serial.print("[Wifi Status] Idling/Connecting: ");
                Serial.println(currentStatus);
                digitalWrite(13,LOW);
                break;
            case WL_NO_SSID_AVAIL:
                Serial.print("[Wifi Status] No SSID Avaliable: ");
                Serial.println(currentStatus);
                digitalWrite(13,LOW);
                break;
            case WL_CONNECTED:
                Serial.print("[Wifi Status] Connected: ");
                Serial.println(currentStatus);
                digitalWrite(13,HIGH);
                break;
            case WL_CONNECT_FAILED:
                Serial.print("[Wifi Status] Connection Failed: ");
                Serial.println(currentStatus);
                digitalWrite(13,LOW);
                break;
            case WL_CONNECTION_LOST:
                Serial.print("[Wifi Status] Connection Lost: ");
                Serial.println(currentStatus);
                digitalWrite(13,LOW);
                break;
            case WL_DISCONNECTED:
                Serial.print("[Wifi Status] Disconnected: ");
                Serial.println(currentStatus);
                digitalWrite(13,LOW);
                break;
            case WL_NO_MODULE:
                Serial.print("[Wifi Status] No Wifi Module Detected: ");
                Serial.println(currentStatus);
                digitalWrite(13,LOW);
                break;
            default:
                Serial.print("[Wifi Status] Unknown Status: ");
                Serial.println(currentStatus);
                digitalWrite(13,LOW);
            }
        }
    }
}
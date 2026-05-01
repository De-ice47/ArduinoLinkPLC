#include "internal/VeloxityLink_Internal.h"
namespace VeloxityLink
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
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] Idling/Connecting: ");
                    Serial.println(currentStatus);
                }
                statusLight(false);
                break;
            case WL_NO_SSID_AVAIL:
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] No SSID Avaliable: ");
                    Serial.println(currentStatus);
                }
                statusLight(false);
                break;
            case WL_CONNECTED:
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] Connected: ");
                    Serial.println(currentStatus);
                }
                statusLight(true);
                break;
            case WL_CONNECT_FAILED:
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] Connection Failed: ");
                    Serial.println(currentStatus);
                }
                statusLight(false);
                break;
            case WL_CONNECTION_LOST:
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] Connection Lost: ");
                    Serial.println(currentStatus);
                }
                statusLight(false);
                break;
            case WL_DISCONNECTED:
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] Disconnected: ");
                    Serial.println(currentStatus);
                }
                statusLight(false);
                break;
            case WL_NO_MODULE:
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] No Wifi Module Detected: ");
                    Serial.println(currentStatus);
                }
                statusLight(false);
                break;
            default:
                if (showSerialOutput)
                {
                    Serial.print("[Wifi Status] Unknown Status: ");
                    Serial.println(currentStatus);
                }
                statusLight(false);
            }
        }
    }
}
#include "Internal/VeloxityLink_Internal.h"
namespace VeloxityLink
{
    void run_network()
    {
        receive_packets();
        wifi_checkStatus();
    }
}
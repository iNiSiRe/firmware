#include "Debug.h"

void Debug::write(const String data)
{
    if (!enabled) {
        return;
    }

    if (mode == DEBUG_MODE_TRANSPORT && transport.connected) {
        transport.send(data);
    } else {
        Serial.println(data);
    }
}

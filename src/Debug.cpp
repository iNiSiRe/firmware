#include "Debug.h"

void Debug::write(const String data)
{
    if (!enabled) {
        return;
    }

    if (mode == DEBUG_MODE_TRANSPORT && transport.connected) {

        DynamicJsonBuffer jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

        root["type"] = "request";
        root["method"] = "post";
        root["action"] = "/api/v1/modules/self/logs";

        String message;
        root.printTo(message);

        transport.send(data);
    } else {
        Serial.println(data);
    }
}

Debug debug;
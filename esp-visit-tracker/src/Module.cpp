#include "Module.h"

void Module::login()
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["method"] = "post";
    root["action"] = "/api/v1/login";
    root["data"]["mac"] = WiFi.macAddress();

    String message;
    root.printTo(message);

    transport.send(message);
}

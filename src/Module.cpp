#include "Module.h"

void Module::login()
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    root["type"] = "request";
    root["method"] = "post";
    root["action"] = "/api/v1/login";
    root["data"]["login"]["MAC"] = WiFi.macAddress();

    String message;
    root.printTo(message);

    transport.send(message);
}

void Module::start()
{
    for (auto unit = units.begin(); unit != units.end(); ++unit) {
        (*unit)->start();
    }
}

void Module::loop()
{
    for (auto unit = units.begin(); unit != units.end(); ++unit) {
        (*unit)->loop();
    }
}

Module module;
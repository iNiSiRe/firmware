#include <Arduino.h>
#include "SwitchUnit.h"
#include "../MessageHandler.h"

void SwitchUnit::setConfig(JsonObject &config)
{
    pin = config["pin"];
}

void SwitchUnit::setVariables(JsonObject &variables)
{
    enabled = variables["enabled"];
}

void SwitchUnit::start()
{
    String method = "/api/v1/units/" + id;
    messageHandler.handlers[method] = std::bind(&SwitchUnit::handle, this, std::placeholders::_1);

    pinMode((uint8_t) pin, OUTPUT);
    digitalWrite((uint8_t) pin, enabled ? HIGH : LOW);
}

void SwitchUnit::handle(JsonObject &data)
{
    enabled = data["enabled"];
    digitalWrite((uint8_t) pin, enabled ? HIGH : LOW);
}

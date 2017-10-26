#include "MessageHandler.h"
#include "Module.h"
#include "Debug.h"
#include "Unit/SwitchUnit.h"
#include "Unit/BeamIntersectionUnit.h"

void MessageHandler::handle(const String string)
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(string);

    if (root["action"] == "/api/v1/login") {

        module.state = MODULE_STATE_AUTHENTICATED;

    } else if (root["action"] == "/api/v1/module/self/config") {

        module.config.debug = root["data"]["config"]["debug"];
        debug.enabled = module.config.debug;
        debug.mode = DEBUG_MODE_TRANSPORT;

    } else if (root["action"] == "/api/v1/module/self/units") {

        for (int i = 0; i < root["data"].measureLength(); i++) {

            Unit *unit;

            if (root["data"][i]["class"] == "SwitchUnit") {
                unit = new SwitchUnit();
            } else if (root["data"][i]["class"] == "BeamIntersectionUnit") {
                unit = new BeamIntersectionUnit();
            } else {
                continue;
            }

            unit->id = root["data"][i]["id"];
            unit->setConfig(root["data"][i]["config"].as<JsonObject>());
            unit->setVariables(root["data"][i]["variables"]);

            module.units.push_back(unit);

        }
    }
}

MessageHandler messageHandler;

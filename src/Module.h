#ifndef ESP_VISIT_TRACKER_MODULE_H
#define ESP_VISIT_TRACKER_MODULE_H


#include <WebSocketsClient.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include "Transport.h"
#include "Config.h"
#include "Unit.h"
#include <list>

enum ModuleState {
    MODULE_STATE_NONE = 0,
    MODULE_STATE_AUTHENTICATED
};

class Module {

public:
    int id;
    ModuleState state = MODULE_STATE_NONE;
    Config config;
    std::list<Unit*> units;

    void login();
    void start();
    void loop();
};

extern Module module;

#endif //ESP_VISIT_TRACKER_MODULE_H

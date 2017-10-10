#ifndef ESP_VISIT_TRACKER_MODULE_H
#define ESP_VISIT_TRACKER_MODULE_H


#include <WebSocketsClient.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include "Transport.h"

class Module {

public:
    int id;

    void login();
};

extern Module module;

#endif //ESP_VISIT_TRACKER_MODULE_H

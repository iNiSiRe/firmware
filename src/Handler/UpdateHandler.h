#ifndef ESP_VISIT_TRACKER_UPDATEHANDLER_H
#define ESP_VISIT_TRACKER_UPDATEHANDLER_H

#include <ESP8266httpUpdate.h>
#include <ArduinoJson.h>

class UpdateHandler {

public:
    void handle(JsonObject &data);

};


#endif //ESP_VISIT_TRACKER_UPDATEHANDLER_H

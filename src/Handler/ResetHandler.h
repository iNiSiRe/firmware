#ifndef ESP_VISIT_TRACKER_RESETHANDLER_H
#define ESP_VISIT_TRACKER_RESETHANDLER_H

#include <ArduinoJson.h>
#include <Esp.h>

class ResetHandler {

public:

    void handle(JsonObject &data) {
        ESP.restart();
    }
};

#endif //ESP_VISIT_TRACKER_RESETHANDLER_H

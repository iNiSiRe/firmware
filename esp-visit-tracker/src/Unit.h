#ifndef ESP_VISIT_TRACKER_UNIT_H
#define ESP_VISIT_TRACKER_UNIT_H

#include <ArduinoJson.h>

class Unit {
public:
    int id;

    virtual void setConfig(const JsonObject config) = 0;
    virtual void setVariables(const JsonObject config) = 0;
    virtual void start() = 0;
    virtual void loop();
};


#endif //ESP_VISIT_TRACKER_UNIT_H

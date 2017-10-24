#ifndef ESP_VISIT_TRACKER_SWITCHUNIT_H
#define ESP_VISIT_TRACKER_SWITCHUNIT_H

#include "../Unit.h"

class SwitchUnit : public Unit {
public:
    int pin;
    bool enabled;

    virtual void setConfig(JsonObject &config) override;
    virtual void setVariables(JsonObject &variables) override;
    virtual void start() override;

    void handle(JsonObject &data);
};


#endif //ESP_VISIT_TRACKER_SWITCHUNIT_H

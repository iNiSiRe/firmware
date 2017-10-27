#ifndef ESP_VISIT_TRACKER_BEAMINTERSECTIONUNIT_H
#define ESP_VISIT_TRACKER_BEAMINTERSECTIONUNIT_H

#include <functional>
#include <BeamIntersectionTracker.h>
#include "../Unit.h"
#include "../InterruptsWrapper.h"

class BeamIntersectionUnit : public Unit
{
public:
    BeamIntersectionUnit();

    struct State {
        bool send = false;
        int direction = 0;
    };

    BeamIntersectionTracker tracker;
    State state;
    uint8_t leftPin, rightPin;

    int previousLeftValue, previousRightValue;
    virtual void setConfig(JsonObject &config) override;
    virtual void setVariables(JsonObject &config) override;

    virtual void start() override;
    void changedLeft();
    void changedRight();

    void intersectionCallback(int direction);
    void loop();
};

#endif //ESP_VISIT_TRACKER_BEAMINTERSECTIONUNIT_H

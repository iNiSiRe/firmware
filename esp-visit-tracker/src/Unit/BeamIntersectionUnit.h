#ifndef ESP_VISIT_TRACKER_BEAMINTERSECTIONUNIT_H
#define ESP_VISIT_TRACKER_BEAMINTERSECTIONUNIT_H

#include <BeamIntersectionTracker.h>
#include "../Unit.h"
#include <functional>

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
    virtual void setConfig(const JsonObject config) override;
    virtual void setVariables(const JsonObject config) override;

    virtual void start() override;
    void changedLeft();
    void changedRight();

    void intersectionCallback(int direction);
    void loop();
};


#endif //ESP_VISIT_TRACKER_BEAMINTERSECTIONUNIT_H

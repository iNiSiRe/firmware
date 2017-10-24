#include <Arduino.h>
#include "BeamIntersectionUnit.h"
#include "../Transport.h"

void BeamIntersectionUnit::setConfig(JsonObject &config)
{
    leftPin = config["leftPin"];
    rightPin = config["rightPin"];
}

void BeamIntersectionUnit::setVariables(JsonObject &config)
{

}

void BeamIntersectionUnit::start()
{
//    attachInterrupt(digitalPinToInterrupt(leftPin), std::bind(&BeamIntersectionUnit::changedLeft, this), CHANGE);
//    attachInterrupt(digitalPinToInterrupt(rightPin), std::bind(&BeamIntersectionUnit::changedRight, this), CHANGE);
}

void BeamIntersectionUnit::changedLeft()
{
    int value = digitalRead(leftPin);

    if (previousLeftValue != value) {
        tracker.intersection(1, value);
        previousLeftValue = value;
    }
}

void BeamIntersectionUnit::changedRight()
{
    int value = digitalRead(rightPin);

    if (previousRightValue != value) {
        tracker.intersection(2, value);
        previousRightValue = value;
    }
}

void BeamIntersectionUnit::intersectionCallback(int direction)
{
    state.send = true;
    state.direction = direction;
}

BeamIntersectionUnit::BeamIntersectionUnit()
{
    tracker.callback = std::bind(&BeamIntersectionUnit::intersectionCallback, this, std::placeholders::_1);
}

void BeamIntersectionUnit::loop()
{
    if (state.send) {
        state.send = false;

        String action = "/api/v1/units/" + id;

        DynamicJsonBuffer json;
        JsonObject& root = json.createObject();
        root["method"] = "patch";
        root["action"] = action;
        root["data"]["unit"]["variables"]["direction"] = state.direction;

        String message;
        root.printTo(message);

        transport.send(message);

        state.direction = 0;
    }
}

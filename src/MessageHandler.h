#ifndef ESP_VISIT_TRACKER_MESSAGEHANDLER_H
#define ESP_VISIT_TRACKER_MESSAGEHANDLER_H

#include <WString.h>
#include <ArduinoJson.h>
#include <map>
#include <functional>

class MessageHandler {

public:

    std::map<const String, std::function<void (const JsonObject)>> handlers;
    void handle(const String string);

};

extern MessageHandler messageHandler;

#endif //ESP_VISIT_TRACKER_MESSAGEHANDLER_H

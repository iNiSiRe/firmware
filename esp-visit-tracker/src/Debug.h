#ifndef ESP_VISIT_TRACKER_DEBUG_H
#define ESP_VISIT_TRACKER_DEBUG_H

#include <WString.h>
#include "Transport.h"

enum DebugMode {
    DEBUG_MODE_SERIAL = 1,
    DEBUG_MODE_TRANSPORT
};

class Debug {

public:
    bool enabled = false;
    DebugMode mode = DEBUG_MODE_SERIAL;

    void write(const String data);
};

extern Debug debug;

#endif //ESP_VISIT_TRACKER_DEBUG_H

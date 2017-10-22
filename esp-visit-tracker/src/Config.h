#ifndef ESP_VISIT_TRACKER_CONFIG_H
#define ESP_VISIT_TRACKER_CONFIG_H


#include <WString.h>

class Config {

public:
    bool debug = false;
    String server = "control.home";
};


#endif //ESP_VISIT_TRACKER_CONFIG_H

#ifndef ESP_VISIT_TRACKER_INTERRUPTS_H
#define ESP_VISIT_TRACKER_INTERRUPTS_H

#include <functional>
#include <list>

class InterruptsWrapper
{
public:
    static std::list<std::function<void()>> handlers;

    static void entryHandler() {
        for (auto it = handlers.begin(); it != handlers.end(); it++) {
            it.operator*();
        }
    };
};

#endif //ESP_VISIT_TRACKER_INTERRUPTS_H

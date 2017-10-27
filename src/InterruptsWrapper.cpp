#include "InterruptsWrapper.h"

std::list<std::function<void()>> InterruptsWrapper::handlers = {};
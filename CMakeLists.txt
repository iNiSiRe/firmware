cmake_minimum_required(VERSION 3.5.2)
project(esp-visit-tracker)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        esp-visit-tracker.cpp
        src/Module.cpp src/Module.h
        src/Transport.cpp src/Transport.h
        src/Debug.cpp src/Debug.h
        src/MessageHandler.cpp src/MessageHandler.h
        src/Config.cpp src/Config.h
        src/Unit.cpp src/Unit.h
        src/Unit/SwitchUnit.cpp src/Unit/SwitchUnit.h
        src/Handler/UpdateHandler.h src/Handler/UpdateHandler.cpp
        src/Unit/BeamIntersectionUnit.cpp src/Unit/BeamIntersectionUnit.h)

include_directories(
        libraries/BeamIntersectionTracker
        vendor/esp8266/cores/esp8266
        vendor/esp8266/libraries/ESP8266WiFi/src
        vendor/esp8266/libraries/ESP8266httpUpdate/src
        vendor/arduinoWebSockets/src
        vendor/ArduinoJson/src
)

add_executable(esp-visit-tracker ${SOURCE_FILES})

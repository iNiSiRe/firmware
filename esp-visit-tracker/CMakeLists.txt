cmake_minimum_required(VERSION 3.5.2)
project(esp-visit-tracker)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        esp-visit-tracker.cpp src/Module.cpp src/Module.h src/Transport.cpp src/Transport.h src/Debug.cpp src/Debug.h)

include_directories(
        /usr/local/lib/esp8266/cores/esp8266
        /usr/local/lib/esp8266/libraries/ESP8266WiFi/src
        libraries/BeamIntersectionTracker
        ../vendor/arduinoWebSockets/src
        ../vendor/ArduinoJson/src
)

add_executable(esp-visit-tracker ${SOURCE_FILES})
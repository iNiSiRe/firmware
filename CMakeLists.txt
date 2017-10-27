cmake_minimum_required(VERSION 3.5.2)
project(esp-visit-tracker)

set(CMAKE_CXX_STANDARD 11)

set(VENDOR_DIR /usr/local/lib/esp8266-firmware-libs)

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
        src/Unit/BeamIntersectionUnit.cpp src/Unit/BeamIntersectionUnit.h src/Handler/ResetHandler.h src/InterruptsWrapper.h src/InterruptsWrapper.cpp)

include_directories(
        libraries/BeamIntersectionTracker
        ${VENDOR_DIR}/esp8266/cores/esp8266
        ${VENDOR_DIR}/esp8266/libraries/ESP8266WiFi/src
        ${VENDOR_DIR}/esp8266/libraries/ESP8266httpUpdate/src
        ${VENDOR_DIR}/arduinoWebSockets/src
        ${VENDOR_DIR}/ArduinoJson/src
)

add_executable(esp-visit-tracker ${SOURCE_FILES})

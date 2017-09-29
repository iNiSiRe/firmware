cmake_minimum_required(VERSION 3.8)
project(arduino-visit-sensor C CXX)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        arduino-visit-sensor.ino)

include_directories(D:\\Software\\Arduino\\libraries)
include_directories(D:\\Software\\Arduino\\hardware\\arduino\\avr\\cores\\arduino)
include_directories(D:\\Software\\Arduino\\hardware\\arduino\\avr\\libraries\\Wire\\src)
#include_directories(D:\\Software\\Arduino\\hardware\\arduino\\avr\\libraries\\VirtualWire)
include_directories(C:\\Users\\inisire\\Documents\\Arduino\\libraries\\BeamIntersectionTracker)

add_executable(arduino-visit-sensor ${SOURCE_FILES})

#set_target_properties(arduino-visit-sensor PROPERTIES LINKER_LANGUAGE CXX)
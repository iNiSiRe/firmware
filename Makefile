SKETCH = esp-visit-tracker.cpp

LIBS = libraries/BeamIntersectionTracker \
  vendor/ArduinoJson/src \
  vendor/arduinoWebSockets/src \
  #vendor/esp8266/libraries/ESP8266WiFi/src \
  #vendor/esp8266/libraries/Hash/src \
  #vendor/esp8266/libraries/ESP8266httpUpdate/src

UPLOAD_PORT = /dev/ttyUSB0
UPLOAD_SPEED = 921600

#ESP_ROOT=./vendor/esp8266
BUILD_ROOT=build

include vendor/makeEspArduino/makeEspArduino.mk
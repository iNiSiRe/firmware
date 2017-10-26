SKETCH = esp-visit-tracker.cpp

VENDOR_DIR = /usr/local/lib/esp8266-firmware-libs

LIBS = libraries/BeamIntersectionTracker \
  $(VENDOR_DIR)/ArduinoJson/src \
  $(VENDOR_DIR)/arduinoWebSockets/src \
  $(VENDOR_DIR)/esp8266/libraries/ESP8266WiFi/src \
  $(VENDOR_DIR)/esp8266/libraries/Hash/src \
  $(VENDOR_DIR)/esp8266/libraries/ESP8266httpUpdate/src \
  $(VENDOR_DIR)/esp8266/libraries/ESP8266HTTPClient/src

UPLOAD_PORT = /dev/ttyUSB0
UPLOAD_SPEED = 921600

ESP_ROOT = $(VENDOR_DIR)/esp8266
BUILD_ROOT = /tmp/esp8266-firmware-build

include $(VENDOR_DIR)/makeEspArduino/makeEspArduino.mk
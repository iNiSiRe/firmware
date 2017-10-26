#!/bin/bash

mkdir /usr/local/lib/esp8266-firmware-libs

git clone https://github.com/bblanchon/ArduinoJson.git /usr/local/lib/esp8266-firmware-libs/ArduinoJson
git clone https://github.com/Links2004/arduinoWebSockets.git /usr/local/lib/esp8266-firmware-libs/arduinoWebSockets
git clone https://github.com/plerup/makeEspArduino.git /usr/local/lib/esp8266-firmware-libs/makeEspArduino
git clone https://github.com/esp8266/Arduino.git -b 2.3.0 /usr/local/lib/esp8266-firmware-libs/esp8266

cd /usr/local/lib/esp8266-firmware-libs/esp8266/tools
python get.py

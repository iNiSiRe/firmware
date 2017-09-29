#!/bin/bash
mkdir vendor
cd vendor
git clone https://github.com/bblanchon/ArduinoJson.git
git clone https://github.com/Links2004/arduinoWebSockets.git
git clone https://github.com/plerup/makeEspArduino.git

git clone https://github.com/esp8266/Arduino.git esp8266
cd esp8266/tools
python get.py

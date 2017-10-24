#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include "src/Transport.h"
#include "src/Module.h"
#include <ArduinoJson.h>

ESP8266WiFiMulti WiFiMulti;

const char *HOST = "control.home";

unsigned long timeout = 0;
bool connected = false;

void ping()
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["action"] = (int) 1;

    String message;
    root.printTo(message);

    transport.send(message);
}

void setup() {
  
    Serial.begin(115200);
    Serial.setDebugOutput(true);

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    WiFiMulti.addAP("Network", "f6d11bf3cd0c232");

    //WiFi.disconnect();
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    Serial.print("MAC address=");
    Serial.println(WiFi.macAddress());

    transport.connect(HOST, 8000);
    module.start();
}

void loop()
{
    transport.loop();
    module.loop();

    if (connected && millis() - timeout > 10000) {
        ping();
        timeout = millis();
    }
}

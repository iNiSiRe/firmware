#include <ArduinoJson.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsClient.h>
#include "BeamIntersectionTracker.h";

ESP8266WiFiMulti WiFiMulti;
WebSocketsClient webSocket;

#define USE_SERIAL Serial

const int MODULE = 3;
const char *HOST = "control.home";

enum Actions {
    ACTION_LOGIN = 4,
    ACTION_CONTROL = 2,
    ACTION_PING = 10
};

enum Modes {
    MODE_DIGITAL = 1,
    MODE_ANALOG = 2
};

unsigned long timeout = 0;
bool connected = false;

void callback(int direction) {
  Serial.print("Direction=");
  Serial.println(direction);
}

BeamIntersectionTracker tracker(callback);

void control(JsonObject& root)
{
    if (!(root.containsKey("pin") && root.containsKey("mode") && root.containsKey("value"))) {
        return;
    }

    pinMode(root["pin"], OUTPUT);

    if (root["mode"] == (int) MODE_DIGITAL) {
        digitalWrite(root["pin"], root["value"]);
    } else if (root["mode"] == (int) MODE_ANALOG) {
        analogWrite(root["pin"], root["value"]);
    }
}

void ping()
{
    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();
    root["action"] = (int) ACTION_PING;

    String message;
    root.printTo(message);

    webSocket.sendTXT(message);
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length)
{
    switch (type) {
        case WStype_DISCONNECTED:
            USE_SERIAL.printf("[WSc] Disconnected!\n");
            connected = false;
            break;

        case WStype_CONNECTED:
        {
            USE_SERIAL.printf("[WS] Connected to url: %s\n",  payload);

            connected = true;

            DynamicJsonBuffer jsonBuffer;
            JsonObject& root = jsonBuffer.createObject();
            root["action"] = (int) ACTION_LOGIN;
            root["module"] = MODULE;

            String message;
            root.printTo(message);

            webSocket.sendTXT(message);
        } break;

        case WStype_TEXT:
            USE_SERIAL.printf("[WSc] get text: %s\n", payload);

            DynamicJsonBuffer  jsonBuffer;
            JsonObject& root = jsonBuffer.parseObject(payload);

            if (root["action"] == (int) ACTION_CONTROL) {
               control(root);
            }

            break;
    }

}

int left = 4, right = 5;
int previousLeftValue, previousRightValue = LOW;

void changedLeft() {
  int value = digitalRead(left);

  if (previousLeftValue != value) {
    tracker.intersection(1, value);
    previousLeftValue = value;
  }
}

void changedRight() {
  int value = digitalRead(right);

  if (previousRightValue != value) {
    tracker.intersection(2, value);
    previousRightValue = value;
  }
}

void setup() {
  
    USE_SERIAL.begin(115200);

    USE_SERIAL.setDebugOutput(true);

    for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
    }

    WiFiMulti.addAP("Network", "f6d11bf3cd0c232");

    //WiFi.disconnect();
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    webSocket.begin(HOST, 8000);
    webSocket.onEvent(webSocketEvent);

    pinMode(left, INPUT);
    pinMode(right, INPUT);

    attachInterrupt(digitalPinToInterrupt(left), changedLeft, CHANGE);
    attachInterrupt(digitalPinToInterrupt(right), changedRight, CHANGE);
}

void loop()
{
    if (connected && millis() - timeout > 30000) {
        ping();
        timeout = millis();
    }

    webSocket.loop();
    tracker.loop();
}

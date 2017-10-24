#include <ESP8266WiFi.h>
#include "Transport.h"
#include "Module.h"
#include "Debug.h"

void Transport::connect(const String host, const uint16_t port)
{
    client.begin(host, port);
    client.onEvent(std::bind(&Transport::handle, &this));
}

void Transport::handle(WStype_t type, uint8_t *data, size_t length)
{
    switch (type) {
        case WStype_DISCONNECTED:
            debug.write("[WS] Disconnected. \n");
            connected = false;
            break;

        case WStype_CONNECTED:
        {
            debug.write("[WS] Connected. \n");
            connected = true;
            module.login();
        } break;

        case WStype_TEXT: {
            debug.write("[WS] Received text. \n");

            if (handler) {
                handler(String(*data));
            } else {
                debug.write("Transport -> handler is not defined");
            }

        } break;

        default: break;
    }
}

void Transport::send(const String data)
{
    if (connected) {
        client.sendTXT(data.c_str());
    }
}

void Transport::loop()
{
    client.loop();
}

#ifndef ESP_VISIT_TRACKER_TRANSPORT_H
#define ESP_VISIT_TRACKER_TRANSPORT_H

#include <WebSocketsClient.h>
#include <functional>

class Transport
{
public:
    bool connected = false;
    std::function<void (String data)> handler;
    WebSocketsClient client;

    void connect(const String host, const uint16_t port);
    void handle(WStype_t type, uint8_t * data, size_t length);
    void send(const String data);
    void loop();
};

extern Transport transport;

#endif //ESP_VISIT_TRACKER_TRANSPORT_H

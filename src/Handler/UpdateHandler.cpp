#include "UpdateHandler.h"
#include "../Debug.h"
#include "../Module.h"

void UpdateHandler::handle(const JsonObject data)
{
    String file = "http://" + module.config.server + "/uploads" + data["file"];
    t_httpUpdate_return result = ESPhttpUpdate.update(file);

    switch(result) {
        case HTTP_UPDATE_FAILED:
            char *string = NULL;
            sprintf(string, "HTTP_UPDATE_FAILED | error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
            debug.write(string);
            break;

        case HTTP_UPDATE_NO_UPDATES:
            debug.write("HTTP_UPDATE_NO_UPDATES");
            break;

        case HTTP_UPDATE_OK:
            debug.write("HTTP_UPDATE_OK");
            break;
    }
}

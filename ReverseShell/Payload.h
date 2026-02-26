/*
  ============================================================
  Payload.h - Base class for payload implementations
  ============================================================

  Defines the Payload interface for executing reverse shell payloads on different operating systems.

  Author: NenshaM
  License: GPL v3
  Version: 1.0.0
  ============================================================
*/

#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <Arduino.h>
#include <Keyboard.h>
#include "KeyboardUtils.h"

/**
 * @brief Abstract base class for payload implementations. Defines the interface for opening a terminal and executing a payload.
 * 
 * Derived classes must implement the openTerminal and executePayload methods for their specific operating system. The constructor initializes the keyboard connection, and the destructor ends it.
 */
class Payload {
public:
    /**
     * @brief Construct a new Payload object and initialize the keyboard.
     */
    Payload() {
        Keyboard.begin();
        // let the host recognize the keyboard
        delay(random(750, 1250)); 
    }

    /**
     * @brief Open a terminal window.
     *
     * @param debug If true, print debug messages to the serial monitor
     */
    virtual void openTerminal(bool debug=false) = 0;

    /**
     * @brief Execute the payload.
     *
     * @param ip_address IP address to connect back to
     * @param port_num Port number to connect back to
     * @param debug If true, print debug messages to the serial monitor
     */
    virtual void executePayload(const char* ip_address, const char* port_num, bool debug=false) = 0;

    /* 
     * Destructor to end the keyboard connection. 
     */
    ~Payload() {
        Keyboard.end();
    }
};

#endif
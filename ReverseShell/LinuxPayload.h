/*
  ============================================================
  LinuxPayload.h - Payload implementation for Linux systems
  ============================================================

  Defines the LinuxPayload class, which implements the Payload interface for Linux operating systems. This class simulates key presses to open a terminal and executes a reverse shell payload using netcat.
  Tested on Debian 13 (trixie) with GNOME.

  Author: NenshaM
  License: GPL v3
  Version: 1.0.0
  ============================================================
*/

#ifndef LINUXPAYLOAD_H
#define LINUXPAYLOAD_H

#include "Payload.h"
#include "Base64.h"

/**
 * @brief Payload implementation for Linux systems. Opens a terminal and executes a reverse shell payload using netcat.
 * 
 * The openTerminal method simulates the key presses to open a terminal window (Ctrl+Alt+T). The executePayload method constructs a reverse shell command using netcat, encodes it in Base64, and then types it into the terminal before pressing Enter.
 * Tested on Debian 13 (trixie) with GNOME
 */
class LinuxPayload : public Payload {
public:
    /**
     * @brief Open a terminal window.
     *
     * @param debug If true, print debug messages to the serial monitor
     */
    void openTerminal(bool debug=false) override;

    /**
     * @brief Execute the payload.
     *
     * @param ip_address IP address to connect back to
     * @param port_num Port number to connect back to
     * @param debug If true, print debug messages to the serial monitor
     */
    void executePayload(const char* ip_address, const char* port_num, bool debug=false) override;
};

#endif
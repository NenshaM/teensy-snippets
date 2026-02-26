#include "KeyboardUtils.h"

void KeyboardUtils::pressKey(const int key, const bool debug) {
  Keyboard.press(key);

  if (debug) {
    Serial.print("Pressed key: ");
    Serial.println(key);
  }

  delay(random(250, 750));
}

void KeyboardUtils::typeCommand(const char *cmd, const bool debug) {
  Keyboard.print(cmd);

  if (debug) {
    Serial.print("Typed command: ");
    Serial.println(cmd);
  }

  delay(random(250, 750));
  Keyboard.press(KEY_ENTER);
  delay(random(25, 75));
  Keyboard.release(KEY_ENTER);
}
#include <Arduino.h>
#include "MeccaBrain.h"

MeccaBrain servo(5);
#define STEP 2

void setup() {
  Serial.begin(100);
  pinMode(5, OUTPUT);
  // This loop initializes communication with the servo 51 times.
  for (int i = 0; i < 51; i++) {
    servo.communicate();
  }
}

void loop() {
  // This loop sets servo colors from 240 to 247.
  for (int i = 240; i <= 247; i++) {
    servo.communicate();
    servo.setServoColor(0, i);
    servo.setServoColor(1, i);
    servo.setServoColor(2, i);
    servo.setServoColor(3, i);
    delay(100);
  }

  // Set servo colors to specific values.
  servo.communicate();
  servo.setServoColor(0, 0xF4);
  servo.setServoColor(1, 0xF2);
  servo.setServoColor(2, 0xF4);
  servo.setServoColor(3, 0xF2);

  // Move servos from 0 to 238 with a step of 2.
  for (int i = 0; i < 239; i += STEP) {
    servo.communicate();
    servo.setServoPosition(0, i);
    servo.setServoPosition(1, 239 - i);
    servo.setServoPosition(2, 0);
    servo.setServoPosition(3, 0);
  }

  // Set servo colors to specific values.
  servo.communicate();
  servo.setServoColor(1, 0xF4);
  servo.setServoColor(0, 0xF2);
  servo.setServoColor(3, 0xF4);
  servo.setServoColor(2, 0xF2);

  // Move servos from 238 to 0 with a step of 2.
  for (int i = 239; i >= 0; i -= STEP) {
    servo.communicate();
    servo.setServoPosition(0, i);
    servo.setServoPosition(1, 239 - i);
    servo.setServoPosition(2, 0);
    servo.setServoPosition(3, 0);
  }
}

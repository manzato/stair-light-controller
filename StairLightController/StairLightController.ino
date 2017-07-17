/*
 * Author "Guillermo Manzato<manzato@gmail.com>"
 * 
 * Wait for a
 */

#include "Light.h"


#define FULL_BRIGHT_LENGTH 7000
#define LOW_BRIGHT_LENGTH 4000
#define LOW_BRIGHTNESS 64

#define LIGHT1_SWITCH_PIN 2
#define LIGHT1_DIM_PIN 3

#define LIGHT2_SWITCH_PIN 4
#define LIGHT2_DIM_PIN 5

#define MOTION_SENSOR1_PIN 7
#define MOTION_SENSOR2_PIN 8

Light light1(LIGHT1_DIM_PIN, LIGHT1_SWITCH_PIN, LOW_BRIGHTNESS, FULL_BRIGHT_LENGTH, LOW_BRIGHT_LENGTH);
Light light2(LIGHT2_DIM_PIN, LIGHT2_SWITCH_PIN, LOW_BRIGHTNESS, FULL_BRIGHT_LENGTH, LOW_BRIGHT_LENGTH);

void setup() {
  pinMode(MOTION_SENSOR1_PIN, INPUT);
  pinMode(MOTION_SENSOR2_PIN, INPUT);
}

void loop() {
  if (digitalRead(MOTION_SENSOR1_PIN) == HIGH) {
    light1.on();
  }
  if (digitalRead(MOTION_SENSOR2_PIN) == HIGH) {
    light2.on();
  }
  light1.compute();
  light2.compute();
}

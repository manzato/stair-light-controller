/*
 * Author "Guillermo Manzato<manzato@gmail.com>"
 * 
 * Wait for a
 */

#include "Light.h"
#include "AvgReader.h"

#define LUMINOCITY_THRESHOLD 100
#define FULL_BRIGHT_LENGTH 7000
#define LOW_BRIGHT_LENGTH 4000
#define LOW_BRIGHTNESS 64

#define LIGHT1_SWITCH_PIN 2
#define LIGHT1_DIM_PIN 3

#define LIGHT2_SWITCH_PIN 4
#define LIGHT2_DIM_PIN 5

#define MOTION_SENSOR1_PIN 7
#define MOTION_SENSOR2_PIN 8

#define LIGHT_SENSOR_PIN 9

Light light1(LIGHT1_DIM_PIN, LIGHT1_SWITCH_PIN, LOW_BRIGHTNESS, FULL_BRIGHT_LENGTH, LOW_BRIGHT_LENGTH);
Light light2(LIGHT2_DIM_PIN, LIGHT2_SWITCH_PIN, LOW_BRIGHTNESS, FULL_BRIGHT_LENGTH, LOW_BRIGHT_LENGTH);

AvgReader ambientLigth(5 /*readings*/, LIGHT_SENSOR_PIN);

void setup() {
  pinMode(MOTION_SENSOR1_PIN, INPUT);
  pinMode(MOTION_SENSOR2_PIN, INPUT);
}


void loop() {
  //Use a rolling average to minimize distortion
  if (ambientLigth.read() <= LUMINOCITY_THRESHOLD) {
    if (digitalRead(MOTION_SENSOR1_PIN) == HIGH) {
      light1.on();
    }
    if (digitalRead(MOTION_SENSOR2_PIN) == HIGH) {
      light2.on();
    }
  }

  //Keep updating the lights, in case the lightning changes during a dim process
  light1.compute();
  light2.compute();
}

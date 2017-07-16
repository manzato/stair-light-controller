/*
Author "Guillermo Manzato<manzato@gmail.com>"
*/

#include "Light.h"

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

Light light(6, 13, 64, 7000, 4000);

void setup() {
  light.on();
}

void loop() {
  light.compute();
}

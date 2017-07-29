
/*
 * Author "Guillermo Manzato<manzato@gmail.com>"
 * 
 * Handles reading an average of the last x readings from a pin. Based on https://www.arduino.cc/en/Tutorial/Smoothing
 * 
*/

#ifndef AvgReader_h
#define AvgReader_h

#include "Arduino.h"

class AvgReader {
  private:
    int data[];
    unsigned int readings;
    unsigned int index = 0;
    bool enoughData = false;
    int pin;
    int total;
   public:
    AvgReader(const unsigned int readings, byte readPin);
    int read();
};

#endif

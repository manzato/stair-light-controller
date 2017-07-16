
#ifndef Light_h
#define Light_h

#include "Arduino.h"

#define DIM_SPEED 10

class Light {
  private:
    byte dimPin;
    byte switchPin;
    byte lowDim;
    unsigned char state = 'O';
    unsigned long duration;
    unsigned long  lowDuration;
    byte target;
    byte current;
    unsigned long lastMillis;
    unsigned long timer;
    void setTarget(byte target);

   public:
    Light(byte dimPin, byte switchPin, byte lowDim, unsigned long duration, unsigned long lowDuration);
    void on();
    bool compute();
};

#endif

#include "Light.h"
#include "Arduino.h"

Light::Light(byte dimPin, byte switchPin, byte lowDim, unsigned long duration, unsigned long lowDuration) {
  this->dimPin = dimPin;
  this->switchPin = switchPin;
  this->lowDim = lowDim;
  this->duration = duration;
  this->lowDuration = lowDuration;
  this->target = 0;
  this->current = 0;
  this->lastMillis = 0;
  this->state = 'O';
  pinMode(this->dimPin, OUTPUT);
  analogWrite(this->dimPin, 0x00);
  pinMode(this->switchPin, OUTPUT);
  analogWrite(this->switchPin, 0x00);
};

void Light::setTarget(byte target) {
  this->target = target;
  this->lastMillis = millis();
  this->timer = millis();
};

void Light::on() {
  this->state = 'H';
  this->setTarget(0xFF);
};

bool Light::compute() {
  if (this->current > 0) {
    digitalWrite(this->switchPin, HIGH);  
  } else {
    digitalWrite(this->switchPin, LOW);  
  }
  
  if (this->target != this->current) {
    if ( ( millis() - this->lastMillis ) >= DIM_SPEED) {     
      if (this->target > this->current) {
        this->current++;
      } else {
        this->current--;
      }
      analogWrite(this->dimPin, this->current);
      this->lastMillis = millis();
    }
  }

  switch(state) {
    case 'H':
      if ( (millis() - this->timer ) > this->duration ) { //Arrived to the 'on' timmer, start dimming
        this->state = 'L';
        this->setTarget(this->lowDim);
      }
      break;
     case 'L':
       if ( (millis() - this->timer ) > this->lowDuration ) { //Arrived to the 'low' timmer, turn off
         this->state = 'O';
         this->setTarget(0x00);
       }
       break;
     case 'O':
        break;
  }

  return true;
};


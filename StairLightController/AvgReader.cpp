#include "AvgReader.h"

AvgReader::AvgReader(const unsigned int readings, byte pin) {
  this->readings = readings;
  this->data[readings];
  this->pin = pin;
  this->total = 0;

    // initialize all the readings to 0, required for substracting the current reading from the total
  for (int i = 0; i < readings; i++) {
    this->data[i] = 0;
  }
}

int AvgReader::read() {
  //remove the 'about to be overwritten' value
  this->total -= this->data[this->index];

  //get a new reading into the mix
  this->data[this->index] = analogRead(this->pin);
  
  //Add the new value to the total
  this->total += this->data[this->index];

  this->index++;
  
  if (this->index >= this->readings) {
    this->enoughData = true;
    this->index = 0;
  }
  
  if (! this->enoughData) {
    //HACK: if we don't have enough data (don't have X readings to average yet), use the index to average, 
    //which effectively has at this point the number of performed readings.
    return this->total / this->index;
  }
  return this->total / this->readings;
}

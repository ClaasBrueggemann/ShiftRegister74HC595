#include "Arduino.h"
#include "ShiftRegister74HC595.h"

ShiftRegister74HC595::ShiftRegister74HC595(uint8_t dataInputPin, uint8_t shiftClockPin, uint8_t storageClockPin)
{
    this->dataInputPin = dataInputPin;
    this->shiftClockPin = shiftClockPin;
    this->storageClockPin = storageClockPin;

    pinMode(this->dataInputPin, OUTPUT);
    pinMode(this->shiftClockPin, OUTPUT);
    pinMode(this->storageClockPin, OUTPUT);
}

void ShiftRegister74HC595::setState(unsigned int state) {
  uint8_t bitCount = sizeof(state) << 2;
  uint8_t mask = 1U << (bitCount - 1);
  
  for (uint8_t i = 0; i < bitCount; i++) {
    uint8_t pinState = (state & mask) ? HIGH : LOW;
    this->shift(pinState);
    
    state <<= 1;
  }

  this->writeToStorageRegister();
}

void ShiftRegister74HC595::shift(byte state) {
    digitalWrite(this->dataInputPin, state);
    digitalWrite(this->shiftClockPin, HIGH);
    digitalWrite(this->shiftClockPin, LOW);
}

void ShiftRegister74HC595::writeToStorageRegister()
{
    digitalWrite(this->storageClockPin, HIGH);
    digitalWrite(this->storageClockPin, LOW); 
}

void ShiftRegister74HC595::reset()
{
  this->setState(0x00);
}
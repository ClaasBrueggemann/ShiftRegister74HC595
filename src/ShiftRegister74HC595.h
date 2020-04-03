#pragma once

class ShiftRegister74HC595
{
    public:
        ShiftRegister74HC595(uint8_t dataInputPin, uint8_t shiftClockPin, uint8_t storageClockPin);
        void setState(unsigned int state);
    private:
        uint8_t dataInputPin;
        uint8_t shiftClockPin;
        uint8_t storageClockPin;

        void writeToStorageRegister();
        void shift(byte state);
        void reset();
};
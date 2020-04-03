# 74HC595 Library for Arduino

This library allows an Arduino board to control an 74HC595 8-stage serial shift register.

## Examples

```c++
#include <ShiftRegister74HC595.h>
const uint8_t DS_PIN = 8; // serial data input
const uint8_t SH_CP_PIN = 9; // shift register clock input
const uint8_t ST_CP_PIN = 10; // storage register clock input

ShiftRegister74HC595 sr(DS_PIN, SH_CP_PIN, ST_CP_PIN);

void setup() {
    // Set stage 0 and stage 7 to high
    sr.setState(0b1000001);
}

void loop() {
}
```
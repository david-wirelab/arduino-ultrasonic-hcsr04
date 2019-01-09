# arduino-ultrasonic-hcsr04

HS-SR04 Ultrasonic sensor distance tracker

## Dependencies

- Arduino UNO or similar board
- HS-SR04 ultrasonic sensor
- Console cable
- male/female wires
- led
- Arduino IDE
- C++

## Wiring

- **HS-SR04**
  - VCC - 5V
  - GND - GND
  - Trig - Digital PIN 9
  - Echo - Digital PIN 10

- **LED**
  - Positive - Digital PIN 4
  - GND - GND

## What does this do

- When `distance` is greater than `upperThreshold` the LED light turns on and stays on until the `distance` drops below `lowerThreshold`.
- Distance is being printed to _serial_ too for verification.

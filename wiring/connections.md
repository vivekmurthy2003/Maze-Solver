# Maze Solver Wiring — 5-Array

## 5-Array IR Sensor → Arduino Nano

| Sensor | Nano |
|---|---|
| S1 / Leftmost | D2 |
| S2 | D3 |
| S3 / Center | D4 |
| S4 | D5 |
| S5 / Rightmost | A0 |
| VCC | 5V |
| GND | GND |

Sensor logic used by the code: `0 = black`, `1 = white`.

## TB6612FNG → Arduino Nano

| TB6612FNG | Nano |
|---|---|
| PWMA | D6 |
| AIN1 | D7 |
| AIN2 | D8 |
| PWMB | D9 |
| BIN1 | D10 |
| BIN2 | D11 |
| STBY | D12 |
| VCC | 5V |
| GND | GND |

## Motors

- Left N20 motor → A01/A02
- Right N20 motor → B01/B02

If one motor rotates in the opposite direction, swap the two wires of that motor.

## Motor Power

- Battery positive → `VM` on TB6612FNG
- Battery negative → TB6612FNG `GND`
- Nano GND → TB6612FNG GND
- Sensor GND → Nano/TB6612 common GND

Do not use the Nano 5V rail as the preferred power source for the motors.

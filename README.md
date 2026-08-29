# Maze Solver Robot

An Arduino Nano based line-maze solver using a 5-channel IR sensor array, TB6612FNG dual motor driver, and two N20 geared motors.

## Overview

This project is designed for a line maze made from a black track on a white background. The robot uses five IR sensors to detect the line and identify junctions. A left-hand maze-solving strategy is used as the starting navigation method, with support for left turns, straight movement, right turns, and U-turns.

## Hardware

- Arduino Nano
- 5-channel digital IR sensor array
- TB6612FNG dual motor driver
- 2 × N20 600 RPM geared motors
- 2 × wheels
- Lightweight chassis
- Battery / suitable motor power supply

## Sensor Arrangement

```text
S1   S2   S3   S4   S5
← LEFT      CENTER      RIGHT →
```

Sensor logic used:

- `0` = black line
- `1` = white background

## Pin Connections

### 5-Array Sensor → Arduino Nano

| Sensor | Nano |
|---|---|
| S1 / Leftmost | D2 |
| S2 | D3 |
| S3 / Center | D4 |
| S4 | D5 |
| S5 / Rightmost | A0 |
| VCC | 5V |
| GND | GND |

### TB6612FNG → Arduino Nano

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

### Motors

- Left motor → A01 / A02
- Right motor → B01 / B02

### Power

- Motor supply positive → TB6612FNG `VM`
- Motor supply negative → TB6612FNG `GND`
- Nano GND, sensor GND, TB6612FNG GND and battery negative must be common.

## Maze Decision Logic

The initial navigation strategy is the **Left-Hand Rule**:

```text
IF left path exists
    turn LEFT
ELSE IF straight path exists
    go STRAIGHT
ELSE IF right path exists
    turn RIGHT
ELSE
    U-TURN
```

The five sensors serve two purposes: maintaining the robot over the line and detecting branches at junctions.

## Project Structure

```text
Maze-Solver/
├── README.md
├── code/
│   ├── maze_solver_5_array.ino
│   └── motor_test.ino
├── wiring/
│   └── connections.md
└── docs/
    └── project-report.md
```

## Development Notes

Start testing at low speed. Verify the sensor logic and motor directions before running the robot through the full maze. Junction detection and turn timing may need tuning for the exact maze dimensions, line width, sensor height, wheel size, and motor behavior.

## Future Improvements

- Path recording using `L`, `R`, `S`, and `B`
- Path simplification for a faster second run
- Automatic sensor calibration
- Improved PID/PD line tracking between junctions
- Junction and finish-line recognition
- Competition-oriented speed optimization

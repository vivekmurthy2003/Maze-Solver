# Maze Solver Robot — Project Report

## 1. Title

**Design and Development of a Line Maze Solver Robot Using Arduino Nano and 5-Array IR Sensors**

## 2. Abstract

This project develops an autonomous line-maze solver robot using an Arduino Nano, 5-channel IR sensor array, TB6612FNG dual motor driver, and two N20 geared DC motors. The robot follows a black line on a white maze surface and detects branches using the left, center, and right sensor groups. A left-hand-rule decision strategy is used to select turns at junctions.

## 3. Objectives

- Develop an autonomous robot capable of navigating a line maze.
- Detect black line paths using five infrared sensors.
- Control two geared DC motors with TB6612FNG.
- Detect left, straight, right, and dead-end conditions.
- Implement a simple maze navigation strategy.

## 4. Hardware

- Arduino Nano
- 5-channel IR sensor array
- TB6612FNG motor driver
- 2 × N20 600 RPM geared motors
- 2 × wheels
- Lightweight chassis
- Battery / suitable motor power supply

## 5. Working Principle

The IR sensors detect the contrast between the black maze line and the white background. In the selected sensor logic, black produces `0` and white produces `1`. During normal line following, the center sensor helps maintain alignment while the left and right sensors detect deviations and branches.

At junctions, the robot uses a left-hand-rule strategy: left path has priority, followed by straight, then right, with a U-turn at a dead end.

## 6. Sensor Arrangement

```text
S1    S2    S3    S4    S5
LEFT       CENTER       RIGHT
```

## 7. Algorithm

```text
Read S1...S5

Detect left path
Detect straight path
Detect right path

If left exists:
    turn left
Else if straight exists:
    continue straight
Else if right exists:
    turn right
Else:
    U-turn
```

## 8. Software

The robot is programmed in the Arduino IDE. Motor speed and turning behavior are controlled through the TB6612FNG. The code also includes line-loss recovery and basic junction handling.

## 9. Testing

Testing should be performed in stages:

1. Verify each IR sensor over black and white surfaces.
2. Verify both motors rotate forward.
3. Verify left and right turns independently.
4. Test individual junctions.
5. Run the robot through the complete maze at low speed.
6. Tune turning delay and base speed for the physical maze.

## 10. Limitations

The simple 5-sensor junction detection depends on the line width, junction geometry, sensor spacing, sensor height, motor response, and battery voltage. The included left-hand-rule implementation is a starting navigation method and may require additional path-memory logic for guaranteed shortest-path performance on arbitrary mazes.

## 11. Future Improvements

- Record decisions as `L`, `R`, `S`, and `B`.
- Simplify the recorded path after reaching the destination.
- Add automatic sensor calibration.
- Use PID/PD tracking between junctions.
- Detect the finish condition reliably.
- Add a second-run shortest-path mode.
- Increase speed after navigation is stable.

## 12. Conclusion

The maze solver demonstrates how an Arduino Nano, 5-array IR sensor, TB6612FNG motor driver, and N20 motors can be integrated into an autonomous line-maze robot. The system can follow the black path, identify junction conditions, and make navigation decisions using a left-hand-rule strategy.

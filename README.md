# EGN-3000L-MCQUEEN--13


Project Overview

This project involves the development of a line-following robot equipped with two IR sensors to detect the line and an ultrasonic sensor to detect obstacles. The robot uses two motors to move its four wheels and follows the line until it 
encounters an obstacle. Upon detecting an obstacle, the robot stops, turns left 45 degrees, moves forward for a second, then turns right 45 degrees and continues following the line.

Components Used
- 2 IR Sensors: Positioned to face downwards to detect the line.
- 1 Ultrasonic Sensor: Positioned at the front to detect obstacles.
- 2 Motors: Connected to the front wheels to drive the robot.
- Arduino Board (e.g., Arduino Uno): Controls the sensors and motors.


Features
- Line Following: The robot uses two IR sensors to detect and follow the line on the ground.
- Obstacle Avoidance: If an obstacle is detected within a specified range (e.g., 20 cm), the robot stops, turns left by 45 degrees, moves forward for one second, turns right by 45 degrees, and then resumes line-following.


Functionality
- Line Following: The robot will move forward while keeping the IR sensors aligned with the line. If the robot detects the line on the left or right sensor, it will adjust its motors accordingly to keep following the path.
- Obstacle Avoidance: If the ultrasonic sensor detects an object within a set range, the robot will stop, perform a small 45-degree left turn, move forward for one second, then make a 45-degree right turn, and rejoin the line.

Wiring
- IR Sensors: Connect the left IR sensor to pin 2 and the right IR sensor to pin 3.
- Ultrasonic Sensor: Connect the trigger pin to pin 4 and the echo pin to pin 5.
- Motors: Connect the left motor to pin 6 and the right motor to pin 7.

Code Overview

- IR Sensor Input: Reads the sensor data and adjusts motor speeds to follow the line.
- Ultrasonic Sensor Input: Measures distance and triggers obstacle avoidance when necessary.
- Motor Control: Uses PWM signals to control motor speeds and direction, allowing the robot to follow the line and maneuver around obstacles.


Setup Instructions

- Connect the components (IR sensors, ultrasonic sensor, motors, and Arduino) according to the wiring configuration.
- Open the Arduino IDE on your computer and paste the provided code into a new sketch.
- Select the appropriate board and port in the Arduino IDE.
- Upload the code to the Arduino board.
- Place the robot on a track with a visible line and power on the robot.
- The robot will start following the line and avoiding obstacles as needed.


Troubleshooting
- Line following not working: Ensure that the IR sensors are properly aligned and the track is clearly visible.
- Obstacle detection not working: Check if the ultrasonic sensor is properly connected and facing forward. Ensure the obstacle is within the detection range.
- Motor issues: Verify that the motor connections to the Arduino are secure.

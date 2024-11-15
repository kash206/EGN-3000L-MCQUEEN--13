// Define motor pins
const int leftMotorForward = 3;
const int leftMotorBackward = 4;
const int rightMotorForward = 5;
const int rightMotorBackward = 6;

// Define IR sensor pins
const int leftIR = 7;
const int rightIR = 8;

// Define ultrasonic sensor pins
const int trigPin = 9;
const int echoPin = 10;

// Define motor speed
const int motorSpeed = 255;  // Max speed

// Define obstacle detection distance
const int obstacleDistance = 20;  // in cm

void setup() {
  // Set motor and sensor pins as outputs or inputs
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorBackward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorBackward, OUTPUT);
  
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);  // Start serial communication for debugging
}

void loop() {
  int distance = getDistance();  // Get distance from ultrasonic sensor
  
  // Check if an obstacle is detected
  if (distance < obstacleDistance) {
    stopMotors();
    delay(500);  // Stop for a moment

    // Turn left 45 degrees
    turnLeft45();
    delay(1000);  // Move for a second to clear the obstacle

    // Turn right 45 degrees
    turnRight45();
    delay(1000);  // Move for a second to rejoin the line

    // Follow the line after obstacle avoidance
    followLine();
  } else {
    followLine();  // Continue following the line
  }
}

// Function to follow the line using IR sensors
void followLine() {
  int leftSensor = digitalRead(leftIR);
  int rightSensor = digitalRead(rightIR);

  if (leftSensor == LOW && rightSensor == LOW) {
    moveForward();  // Move forward if both sensors are on the line
  } else if (leftSensor == LOW) {
    turnLeft();  // Turn left if the left sensor detects the line
  } else if (rightSensor == LOW) {
    turnRight();  // Turn right if the right sensor detects the line
  } else {
    stopMotors();  // Stop if neither sensor detects the line
  }
}

// Function to get distance from ultrasonic sensor
int getDistance() {
  long duration, distance;
  
  // Send a pulse from the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin to get the distance
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  // Calculate the distance in cm
  return distance;
}

// Function to move the bot forward
void moveForward() {
  analogWrite(leftMotorForward, motorSpeed);
  analogWrite(rightMotorForward, motorSpeed);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
}

// Function to stop the motors
void stopMotors() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, 0);
}

// Function to turn the bot left
void turnLeft() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, motorSpeed);
  analogWrite(leftMotorBackward, motorSpeed);
  analogWrite(rightMotorBackward, 0);
}

// Function to turn the bot right
void turnRight() {
  analogWrite(leftMotorForward, motorSpeed);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, motorSpeed);
}

// Function to turn the bot left 45 degrees
void turnLeft45() {
  analogWrite(leftMotorForward, 0);
  analogWrite(rightMotorForward, motorSpeed);
  analogWrite(leftMotorBackward, motorSpeed);
  analogWrite(rightMotorBackward, 0);
  delay(500);  // Adjust this delay to achieve a 45-degree turn
}

// Function to turn the bot right 45 degrees
void turnRight45() {
  analogWrite(leftMotorForward, motorSpeed);
  analogWrite(rightMotorForward, 0);
  analogWrite(leftMotorBackward, 0);
  analogWrite(rightMotorBackward, motorSpeed);
  delay(500);  // Adjust this delay to achieve a 45-degree turn
}

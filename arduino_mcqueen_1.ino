// Pin Definitions
const int IR_L = 2;   // Left IR sensor
const int IR_R = 3;   // Right IR sensor
const int MotorA1 = 9; // Motor A direction control
const int MotorA2 = 10;
const int MotorB1 = 6; // Motor B direction control
const int MotorB2 = 5;

// Motor speed
const int motorSpeed = 150;

void setup() {
  pinMode(IR_L, INPUT);
  pinMode(IR_R, INPUT);
  
  pinMode(MotorA1, OUTPUT);
  pinMode(MotorA2, OUTPUT);
  pinMode(MotorB1, OUTPUT);
  pinMode(MotorB2, OUTPUT);
}

void loop() {
  int leftSensor = digitalRead(IR_L);
  int rightSensor = digitalRead(IR_R);

  if (leftSensor == LOW && rightSensor == LOW) {
    // Both sensors on white - move forward
    moveForward();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Left sensor on white, right sensor on black - turn right slightly
    turnRightSlight();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Right sensor on white, left sensor on black - turn left slightly
    turnLeftSlight();
  } else {
    // Both sensors on black - assume forward movement
    moveForward();
  }
}

// Functions to control movement
void moveForward() {
  analogWrite(MotorA1, motorSpeed);
  analogWrite(MotorA2, 0);
  analogWrite(MotorB1, motorSpeed);
  analogWrite(MotorB2, 0);
}

void turnRightSlight() {
  analogWrite(MotorA1, motorSpeed);
  analogWrite(MotorA2, 0);
  analogWrite(MotorB1, motorSpeed / 2); // Slower speed for slight turn
  analogWrite(MotorB2, 0);
}

void turnLeftSlight() {
  analogWrite(MotorA1, motorSpeed / 2); // Slower speed for slight turn
  analogWrite(MotorA2, 0);
  analogWrite(MotorB1, motorSpeed);
  analogWrite(MotorB2, 0);
}

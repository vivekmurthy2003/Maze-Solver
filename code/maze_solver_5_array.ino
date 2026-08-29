// ============================================================
// 5-ARRAY LINE MAZE SOLVER
// Arduino Nano + TB6612FNG + 2 x N20 Motors
// BLACK LINE = 0
// WHITE = 1
// ============================================================

const byte S1 = 2;    // Far left
const byte S2 = 3;    // Left
const byte S3 = 4;    // Center
const byte S4 = 5;    // Right
const byte S5 = A0;   // Far right

const byte PWMA = 6;
const byte AIN1 = 7;
const byte AIN2 = 8;
const byte PWMB = 9;
const byte BIN1 = 10;
const byte BIN2 = 11;
const byte STBY = 12;

#define BLACK 0

int baseSpeed = 90;
int turnSpeed = 110;
int lastError = 0;

void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);
  stopMotors();
  delay(1000);
}

void loop() {
  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);

  bool left = (s1 == BLACK || s2 == BLACK);
  bool straight = (s3 == BLACK);
  bool right = (s4 == BLACK || s5 == BLACK);

  // Junction handling: left-hand rule.
  if (left && straight) {
    turnLeft();
    return;
  }

  if (left && right) {
    turnLeft();
    return;
  }

  if (left && !straight && !right) {
    turnLeft();
    return;
  }

  if (right && straight) {
    turnRight();
    return;
  }

  if (right && !straight && !left) {
    turnRight();
    return;
  }

  if (!left && !straight && !right) {
    searchLine();
    return;
  }

  // Normal line following.
  int error = 0;
  if (s1 == BLACK) error -= 4;
  if (s2 == BLACK) error -= 2;
  if (s4 == BLACK) error += 2;
  if (s5 == BLACK) error += 4;

  lastError = error;

  int correction = error * 22;
  int leftSpeed = constrain(baseSpeed + correction, 0, 200);
  int rightSpeed = constrain(baseSpeed - correction, 0, 200);

  leftMotor(leftSpeed);
  rightMotor(rightSpeed);
}

void turnLeft() {
  leftMotor(-turnSpeed);
  rightMotor(turnSpeed);
  delay(140);

  while (digitalRead(S3) != BLACK) {
    leftMotor(-turnSpeed);
    rightMotor(turnSpeed);
  }

  goStraightBriefly();
}

void turnRight() {
  leftMotor(turnSpeed);
  rightMotor(-turnSpeed);
  delay(140);

  while (digitalRead(S3) != BLACK) {
    leftMotor(turnSpeed);
    rightMotor(-turnSpeed);
  }

  goStraightBriefly();
}

void turnAround() {
  leftMotor(turnSpeed);
  rightMotor(-turnSpeed);
  delay(280);

  while (digitalRead(S3) != BLACK) {
    leftMotor(turnSpeed);
    rightMotor(-turnSpeed);
  }

  goStraightBriefly();
}

void goStraightBriefly() {
  leftMotor(baseSpeed);
  rightMotor(baseSpeed);
  delay(50);
}

void searchLine() {
  if (lastError < 0) {
    leftMotor(-70);
    rightMotor(70);
  } else {
    leftMotor(70);
    rightMotor(-70);
  }
}

void leftMotor(int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, speed);
  } else if (speed < 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, -speed);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 0);
  }
}

void rightMotor(int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, speed);
  } else if (speed < 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, -speed);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 0);
  }
}

void stopMotors() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

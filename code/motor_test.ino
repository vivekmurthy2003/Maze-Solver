// ============================================================
// TB6612FNG MOTOR TEST
// Arduino Nano
// ============================================================

const byte PWMA = 6;
const byte AIN1 = 7;
const byte AIN2 = 8;

const byte PWMB = 9;
const byte BIN1 = 10;
const byte BIN2 = 11;

const byte STBY = 12;

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);

  // Both motors forward
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  analogWrite(PWMA, 150);
  analogWrite(PWMB, 150);
}

void loop() {
  // Motors run continuously.
}

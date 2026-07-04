const int PWMA = 9, AIN1 = 8, AIN2 = 7;

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
}

void motorA(int speed) {
  digitalWrite(AIN1, speed > 0);
  digitalWrite(AIN2, speed < 0);
  analogWrite(PWMA, abs(speed));
}

void loop() {
  motorA(150); delay(1500);
  motorA(0); delay(500);
  motorA(-150); delay(1500);
  motorA(0); delay(1500);
}
#include <Servo.h>
Servo servoTilt;  // yoay ngang
int y;
int prevY = 90;
void setup() {
  Serial.begin(9600);
  servoTilt.attach(5);  // Ngang gắn vào 6
  servoTilt.write(prevY);
}
void Pos() {
  if (y < 0) {
    prevY += 4;
    if (prevY >= 180) {
      prevY -= 4;
    }
    servoTilt.write(prevY);
  }
  if (y > 0) {
    prevY -= 4;
    if (prevY <= 0) {
      prevY += 4;
    }
    servoTilt.write(prevY);
  }
}

void loop() {
  if (Serial.available() > 0) {
    if (Serial.read() == 'Y')  // Nhận ký tự y
    {
      y = Serial.parseInt();
      Pos();
    }
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
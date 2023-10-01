#include <Servo.h>
Servo servoTilt;  // Xoay dọc
Servo servoPan;   // Xoay ngang
int x;
int y;
int prevX = 0;
int prevY = 90;
void setup() {
  Serial.begin(9600);
  servoTilt.attach(5);  // Dọc gắn vào 5
  servoPan.attach(6);   // Ngang gắn vào 6
  servoTilt.write(90);
  servoPan.write(90);
}
void Pos() {
  if (x > 0) {
    prevX += 2;
    if (prevX >= 180) {
      prevX -= 2;
    }
  }
  if (x < 0) {
    prevX -= 2;
    if (prevX <= 0) {
      prevX += 2;
    }
  }
  if (y < 0) {
    prevY += 2;
    if (prevY >= 180) {
      prevY -= 2;
    }
  }
  if (y > 0) {
    prevY -= 2;
    if (prevY <= 0) {
      prevY += 2;
    }
  }
  servoPan.write(prevX);
  servoTilt.write(prevY);
}

void loop() {
  if (Serial.available() > 0) {
    if (Serial.read() == 'X')  // Nhận ký tự X
    {
      x = Serial.parseInt();
      if (Serial.read() == 'Y')  // Nhận ký tự Y
      {
        y = Serial.parseInt();
        Pos();
      }
    }
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
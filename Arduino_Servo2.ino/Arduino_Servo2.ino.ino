#include <Servo.h>
Servo servoTilt;  // Xoay dọc
Servo servoPan;   // Xoay ngang
int x;
int y;
int prevX = 90;
int prevY = 60;
int a = 1.5 ; // angle
void setup() {
  Serial.begin(9600);
  servoTilt.attach(5);  // Dọc gắn vào 5
  servoPan.attach(6);   // Ngang gắn vào 6
  servoTilt.write(60);
  servoPan.write(90);
}
void Pos() {
  if (x > 0) {
    prevX += a;
    if (prevX >= 180) {
      prevX -= a;
    }
  }
  if (x < 0) {
    prevX -= a;
    if (prevX <= 0) {
      prevX += a;
    }
  }
  if (y < 0) {
    prevY += a;
    if (prevY >= 180) {
      prevY -= a;
    }
  }
  if (y > 0) {
    prevY -= a;
    if (prevY <= 0) {
      prevY += a;
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
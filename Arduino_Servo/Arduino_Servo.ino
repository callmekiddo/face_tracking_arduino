#include <Servo.h>
Servo servoTilt;  // Xoay dọc
Servo servoPan;   // Xoay ngang
int currentPosX = 90;
int targetPosX;
int currentPosY = 90;
int targetPosY;
int x;
int y;
int prevX;
int prevY;
void setup() {
  Serial.begin(9600);
  servoTilt.attach(5);  // Dọc gắn vào 5
  servoPan.attach(6);   // Ngang gắn vào 6
  servoTilt.write(90);
  servoPan.write(90);
}
void Pos() {
  if (prevX != x || prevY != y) {
    int servoX = map(x, 300, -300, 0, 180);
    int servoY = map(y, 300, -300, 180, 0);
    servoPan.write(servoX);   // Đặt góc quay cho servoPan
    servoTilt.write(servoY);  // Đặt góc quay cho servoTilt
  }
  
}

void loop() {
  if (Serial.available() > 0) {
    if (Serial.read() == 'X')  // Nhận ký tự X
    {
      x = Serial.parseInt();
      Pos();
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
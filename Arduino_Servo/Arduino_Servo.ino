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
    int servoX = map(x, -1, 1, 0, 180);
    int servoY = map(y, -1, 1, 180, 0);
    targetPosX = servoX;
    targetPosY = servoY;
  }

  if (currentPosX != targetPosX) {
    if (currentPosY != targetPosY) {
      if (currentPosX < targetPosX) {
        currentPosX++;  // Tăng góc quay lên
        if (currentPosY < targetPosY) {
          currentPosY++;  // Giảm góc quay xuống
        }
      }
      if (currentPosX < targetPosX) {
        currentPosX++;  // Tăng góc quay lên
        if (currentPosY > targetPosY) {
          currentPosY--;  // Giảm góc quay xuống
        }
      }
      if (currentPosX > targetPosX) {
        currentPosX--;  // Tăng góc quay lên
        if (currentPosY < targetPosY) {
          currentPosY++;  // Giảm góc quay xuống
        }
      }
      if (currentPosX > targetPosX) {
        currentPosX--;
        if (currentPosY > currentPosY) {
          currentPosY--;
        }
      }
    }
  }
  servoPan.write(currentPosX);   // Đặt góc quay cho servoPan
  servoTilt.write(currentPosY);  // Đặt góc quay cho servoTilt
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
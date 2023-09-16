#include<Servo.h>
Servo servoPan; // Xoay ngang
int currentPos = 90;
int targetPos;
int x;
int prevX;
void setup()
{
  Serial.begin(9600);
  servoPan.attach(6); // Ngang gắn vào 6
  servoPan.write(90);
}
void Pos()
{
  if(prevX != x)
  {
    int servoX = map(x, 300, -300, 180, 0);
    servoX = min(servoX, 180);
    servoX = max(servoX, 0);
    targetPos = servoX; // Đặt vị trí mục tiêu mới
    
  }

  if (currentPos != targetPos) {
    if (currentPos < targetPos) {
      currentPos++; // Tăng góc quay lên
    } else {
      currentPos--; // Giảm góc quay xuống
    }
    servoPan.write(currentPos); // Đặt góc quay cho servoPan
  }
}
void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {
      x = Serial.parseInt();
      Pos();
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}
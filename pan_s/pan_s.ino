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
    int servoX = map(x, -1, 1, 0, 180);
    targetPos = servoX; // Đặt vị trí mục tiêu mới
    
  }

  if (currentPos != targetPos) {
    if (currentPos < targetPos) {
      currentPos++; // Tăng góc quay lên
      if(currentPos > 180) {
        currentPos--;
      }
    } else {
      currentPos--; // Giảm góc quay xuống
      if(currentPos <= 0) {
        currentPos++;
      }
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
#include<Servo.h>
Servo servoTilt; // YoaY ngang
int currentPos = 90;
int targetPos;
int y;
int prevY;
void setup()
{
  Serial.begin(9600);
  servoTilt.attach(5); // Ngang gắn vào 6
  servoTilt.write(90);
}
void Pos()
{
  if(prevY != y)
  {
    int servoY = map(y, -300, 300, 180, 0);
    servoY = min(servoY, 180);
    servoY = max(servoY, 0);
    targetPos = servoY; // Đặt vị trí mục tiêu mới
    
  }

  if (currentPos != targetPos) {
    if (currentPos < targetPos) {
      currentPos++; // Tăng góc quaY lên
    } else {
      currentPos--; // Giảm góc quaY Yuống
    }
    servoTilt.write(currentPos); // Đặt góc quaY cho servoTilt
  }
}
void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'Y')
    {
      y = Serial.parseInt();
      Pos();
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}
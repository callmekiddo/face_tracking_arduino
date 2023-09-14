#include<Servo.h>
Servo servoTil; //Xoay doc
Servo servoPan; //Xoay ngang
int x;
int y;
int prevX;
int prevY;
void setup()
{
  Serial.begin(9600);
  servoTil.attach(5); //Doc gan vao 5
  servoPan.attach(6); //Ngang gan vao 6
  servoTil.write(90);
  servoPan.write(90);
}
void Pos()
{
  if(prevX != x || prevY != y)
  {
    int servoX = map(x, 600, 0, 70, 179);
    int servoY = map(y, 450, 0, 179, 95);
    servoX = min(servoX, 179);
    servoX = max(servoX, 70);
    servoY = min(servoY, 179);
    servoY = max(servoY, 95);
    
    servoPan.write(servoX);
    servoTil.write(servoY);
  }
}
void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {
      x = Serial.parseInt();
      if(Serial.read() == 'Y')
      {
        y = Serial.parseInt();
       Pos();
      }
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}
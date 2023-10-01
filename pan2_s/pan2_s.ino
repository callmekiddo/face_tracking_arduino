#include <Servo.h>
Servo servoPan;  // Xoay ngang
int x;
int prevX = 90;
void setup() {
  Serial.begin(9600);
  servoPan.attach(6);  // Ngang gắn vào 6
  servoPan.write(prevX);
}
void Pos() {
  if (x > 0) {
    prevX += 4;
    if (prevX >= 180) {
      prevX -= 4;
    }
    servoPan.write(prevX);
  }
  if (x < 0) {
    prevX -= 4;
    if (prevX <= 0) {
      prevX += 4;
    }
    servoPan.write(prevX);
  }
}

void loop() {
  if (Serial.available() > 0) {
    if (Serial.read() == 'X')  // Nhận ký tự X
    {
      x = Serial.parseInt();
      Pos();
    }
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
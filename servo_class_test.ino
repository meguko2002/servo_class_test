#include <Servo.h>
Servo *myservo[2];    //静的にメモリを確保する必要がある([]はNG)
const int len = sizeof(myservo) / sizeof(myservo[0]);

void turn(Servo *servo) {
  int pos;
  for (pos = 0; pos <= 180; pos += 1) turn_d(pos,servo);
  for (pos = 180; pos >= 0; pos -= 1) turn_d(pos,servo);
}

void turn_d(int pos, Servo *servo) {
  servo->write(pos);
  Serial.println(servo->read());
  delay(15);
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < len; i++) {
    myservo[i] = new Servo;   //インスタンスを生成
    myservo[i]->attach(8 + i);
  }
  for (int i = 0; i < len; i++) {
    turn(myservo[i]);
    myservo[i]-> detach();
  }
}

void loop() {
}

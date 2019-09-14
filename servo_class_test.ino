#include <Servo.h>
Servo *myservo[2];
const int len = sizeof(myservo) / sizeof(myservo[0]);

void turn(Servo *servo) {
  int pos;
  for (pos = 0; pos <= 180; pos += 1) {
    servo->write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    servo->write(pos);
    delay(15);
  }
}


void setup() {
  for (int i = 0; i < len; i++) {
    myservo[i] = new Servo;
    myservo[i]->attach(8 + i);
  }
}

void loop() {
  for (int i = 0; i < len; i++) {
    turn(myservo[i]);
  }
}

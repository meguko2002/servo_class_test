#include <Servo.h>
Servo myservo[2];    //静的にメモリを確保する必要がある([]はNG)
const int len = sizeof(myservo) / sizeof(myservo[0]);

void turn(const Servo &servo) {
  /*参照渡し, 元の変数に別名をつける記法
    変更すると呼び出し元の変数も書き換えられる*/
  int pos;
  for (pos = 0; pos <= 180; pos += 1) turn_d(pos, servo);
  for (pos = 180; pos >= 0; pos -= 1) turn_d(pos, servo);
}

void turn_d(int pos, Servo servo) {
  servo.write(pos);
  delay(15);
}

void setup() {
  Serial.begin(9600);
  char buffer[30];
  for (int i = 0; i < len; i++) {
    myservo[i].attach(8 + i);
  }
  int j = 0;
  sprintf(buffer, " &myservo[0] = %p, &myservo[1] = %p", &myservo[0], &myservo[1]);
  Serial.println(buffer);
  sprintf(buffer, "  myservo    = %p,  myservo + 1= %p", myservo, myservo + 1);
  Serial.println(buffer);
  for (int i = 0; i < len; i++) {
    turn(myservo[i]);
    myservo[i]. detach();
  }
}

void loop() {
}

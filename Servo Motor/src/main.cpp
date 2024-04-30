#include <Arduino.h>
#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(D4);
  
}

void loop() {
  myservo.write(90);
  for(int pos = 0; pos <= 180; pos += 1){
    myservo.write(pos);
    delay(15);
  }
  for(int pos = 100; pos >= 0; pos -= 1){
    myservo.write(pos);
    delay(15);
  }
}
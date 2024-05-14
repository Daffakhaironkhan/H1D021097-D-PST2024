
#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myServo;
int trigPin = D4;
int echoPin = D5;
int ledOpen = D8;
int ledClose = D6;

LiquidCrystal_I2C lcd(0x27, 15, 1);
int SDA_pin = D1;
int SCL_pin = D2;

long duration;
int distance;

void setup()
{
  pinMode(ledOpen, OUTPUT);
  pinMode(ledClose, OUTPUT);
  myServo.attach(D3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  // lcd.setCursor(0,0);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Jarak : "); 
  lcd.print(distance); 
  lcd.print(" cm");
  
  if (distance <= 10)
  {
    myServo.write(180);
    digitalWrite(ledClose, LOW);
    digitalWrite(ledOpen, HIGH);
    delay(1000);
  }
  else if (distance > 10)
  {
    myServo.write(0);
    digitalWrite(ledOpen, LOW);
    digitalWrite(ledClose, HIGH);
    delay(1000);
  }
}


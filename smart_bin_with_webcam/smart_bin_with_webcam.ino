#include <Servo.h>
Servo servoMain;
Servo servoMain2;

int trigpin = 3;
int echopin = 2;
int trigpin2 = 5;
int echopin2 = 4;

int ledPin = 13;

int distance;
float duration;
float cm;
float df;

int incomingByte; 

void setup()
{
  servoMain.attach(6);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  servoMain2.attach(7);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }
  
  digitalWrite(trigpin, LOW);
  delay(2);  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigpin, LOW);  
  duration = pulseIn(echopin, HIGH);  
  cm = (duration/58.82);
  distance = cm;
  //Serial.print("1: ");
  //Serial.println(distance);
  

  if (incomingByte == 'H' && distance < 30) {
      servoMain.write(90);
  }
  if (incomingByte == 'L' || distance > 30) {
      servoMain.write(0);
  }

  digitalWrite(trigpin2, LOW);
  delay(2);  
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigpin2, LOW);  
  duration = pulseIn(echopin2, HIGH);  
  cm = (duration/58.82);
  distance = cm;
  
  if(distance < 30)
     digitalWrite(ledPin, HIGH);
  else
     digitalWrite(ledPin, LOW);
  
  if (incomingByte == 'H' && distance < 30) {
     servoMain2.write(90);
  }
  if (incomingByte == 'L' || distance > 30) {
      servoMain2.write(0);
  }
  
  delay(500);
}

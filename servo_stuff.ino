#include <Servo.h> 
Servo myservo;
const int buttonPin = 2; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin) == HIGH){
    myservo.write(180);
  } else { 
    myservo.write(0);
  }
}

// hello

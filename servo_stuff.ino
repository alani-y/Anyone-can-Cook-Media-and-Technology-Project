#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int buttonPin = 2;
const int fridgePin = 4;
int pos = 0;    // variable to store the servo position
int inputVoltage = 0;

int buttonState = 0; // button status variable

void setup() {
  Serial.begin(9600); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo 
  pinMode(buttonPin, INPUT);
  pinMode(fridgePin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial.println("HIGH");
    rotateServo(180);
  }
  else{
    Serial.println("low");
  }
  
  Serial.println(digitalRead(fridgePin));

  if (digitalRead(fridgePin) == 0) {  // this function opens the fridge when linguine approaches
    rotateServo(90);
  }

}

int rotateServo(int x){
  //int analogValue = analogRead(A5);
  //inputVoltage = (analogValue * 5.0)/ 1024.0;
  //Serial.println(inputVoltage);
  for (pos = 0; pos <= x; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = x; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}




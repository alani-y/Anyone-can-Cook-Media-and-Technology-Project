#include <Servo.h>

Servo fridgeservo;
Servo armservo;
Servo remyservo;

Servo servo[] = {fridgeservo, armservo, remyservo}; // This array stores all the servo objects

const int buttonPin1 = 12;
const int buttonPin2 = 4;
const int buttonPin3 = 8;
const int servoPins[] = {3,5,7};

int pos = 0;    // variable to store the servo position
int buttonState1 = 0; // button status variable
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  Serial.begin(9600); 
  for(int i = 0; i < 3; i++) // assigns each servo object a pin on the arduino
  {
    servo[i].attach(servoPins[i]);
  }
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
   // function to open the fridge
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == HIGH) {
    rotateServo(90, 0);
  }
  else {
    Serial.println("low");
  }
  // button that moves Linguine's arm
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH){
    rotateServo(90, 1);
  }
  // button that swivels remy around
  buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 == HIGH){
    rotateServo(90, 2);
  }
}

int rotateServo(int degrees, int i){ // function that controls the servos

  for (pos = 0; pos <= degrees; pos += 1) { // goes from 0 degrees to 180 degrees
    Serial.println("rotate");
    servo[i].write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = degrees; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo[i].write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

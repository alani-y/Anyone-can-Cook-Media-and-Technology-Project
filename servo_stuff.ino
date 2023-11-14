#include <Servo.h>

Servo floorservo1;
Servo floorservo2;
Servo fridgeservo;
Servo armservo;
Servo remyservo;

Servo servo[5] = {floorservo1, floorservo2, fridgeservo, armservo, remyservo};

const int buttonPin = 2;
const int fridgePin = 7;
const int servoPins[] = {9};
int pos = 0;    // variable to store the servo position
int buttonState = 0; // button status variable
int fridgeState = 0; // if the fridge is open or not

void setup() {
  Serial.begin(9600); 
  for(int i = 0; i < 1; i++)
  {
    servo[i].attach(servoPins[i]);
  }
  pinMode(buttonPin, INPUT);
  pinMode(fridgePin, INPUT);
}

void loop() {
  Serial.println(servoPins[0]);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    Serial.println("HIGH");
    rotateServo(180, 0);
  }
  else{
    Serial.println("low");
  }
  fridgeState = digitalRead(fridgePin);
  Serial.println(fridgeState);
  if (fridgeState == 1) {
    rotateServo(90, 2);
  }
}


int rotateServo(int degrees, int i){

  for (pos = 0; pos <= degrees; pos += 1) { // goes from 0 degrees to 180 degrees
    Serial.println("hi");
    servo[i].write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = degrees; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo[i].write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

#include <Servo.h>

Servo floorservo1;
Servo floorservo2;
Servo fridgeservo;
Servo armservo;

Servo servo[] = {floorservo1, floorservo2, fridgeservo, armservo}; // This array stores all the servo objects

const int buttonPin = 2;
const int fridgePin = 7;
const int servoPins[] = {9, 5, 3, 10};
int pos = 0;    // variable to store the servo position
int buttonState = 0; // button status variable
int fridgeState = 0; // if the fridge is open or not

void setup() {
  Serial.begin(9600); 
  for(int i = 0; i < 2; i++) // assigns each servo object a pin on the arduino
  {
    servo[i].attach(servoPins[i]);
  }
  pinMode(buttonPin, INPUT);
  pinMode(fridgePin, INPUT);
}

void loop() {
  Serial.println(servoPins[0]);
  Serial.println(servoPins[1]);
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
  if (fridgeState == 0) {
    Serial.println("open");
    rotateServo(90, 1);
    delay(360);
  }
}


int rotateServo(int degrees, int i){ // function that controls the servos

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

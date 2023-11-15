#include <Servo.h>

Servo floorservo;
Servo floorservo2;
Servo fridgeservo;
Servo armservo;

Servo servo[] = {fridgeservo, floorservo, floorservo2, armservo}; // This array stores all the servo objects

const int buttonPin = 12;
const int buttonPinMove = 4;
const int fridgePin = 11;
const int servoPins[] = {3, 5, 9, 10};
int pos = 0;    // variable to store the servo position
int buttonState = 0; // button status variable
int fridgeState = 0; // if the fridge is open or not
bool rotateOnce = true;

void setup() {
  Serial.begin(9600); 
  for(int i = 0; i < 4; i++) // assigns each servo object a pin on the arduino
  {
    servo[i].attach(servoPins[i]);
  }
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinMove, INPUT);
}

void loop() {
   // function to open the fridge
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    rotateServo(90, 0, false);
    
  }
  
  // button that moves Linguine
  int movePinRead = digitalRead(buttonPinMove);
  if (movePinRead == HIGH){
    rotateServo(180, 1, true);
  }

  fridgeState = digitalRead(fridgePin);
  Serial.println(fridgePin);
}


int rotateServo(int degrees, int i, bool rotateOnce){ // function that controls the servos

  for (pos = 0; pos <= degrees; pos += 1) { // goes from 0 degrees to 180 degrees
    servo[i].write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  if (rotateOnce == false){ // returns the servo back to its original position
    for (pos = degrees; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo[i].write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
}

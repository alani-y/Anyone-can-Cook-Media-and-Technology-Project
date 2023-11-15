#include <Servo.h>

Servo floorservo;
Servo floorservo2;
Servo fridgeservo;
Servo armservo;

Servo servo[] = {fridgeservo, armservo}; // This array stores all the servo objects

const int buttonPin = 12;
const int buttonPinMove = 4;
const int linguinePositionPin = 8;
const int servoPins[] = {3, 5};
int pos = 0;    // variable to store the servo position
int buttonState = 0; // button status variable
bool rotateOnce = true;
int linguinePosition = 0; // variable that detect if the copper tape circuits are open or closed because of linguine

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
    rotateServo(90, 0);
  }
  else {
    Serial.println("low");
  }
  // button that moves Linguine's arm
  int movePinRead = digitalRead(buttonPinMove);
  if (movePinRead == HIGH){
    rotateServo(90, 1);
  }
  
  int linguinePosition = digitalRead(linguinePositionPin); // checks if linguine is closing a paper circuit
  Serial.println(linguinePosition);
  if (linguinePosition == 1) {
    Serial.println(linguinePosition);
    rotateServo(90, 1);
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

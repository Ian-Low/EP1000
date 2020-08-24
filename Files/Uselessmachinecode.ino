// Sweep
// by BARRAGAN <http://barraganstudio.com>
// This example code is in the public domain.

#include <Servo.h>

const int  buttonPin = 3;
int buttonState = 0;

Servo myservo;  // create servo object to control a servo
                             // a maximum of eight servo objects can be created
int pos;                // variable to store the servo position
short timeDelay;

void setup()
{
  pinMode(buttonPin, INPUT);
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  buttonState = digitalRead(buttonPin);  // Read the button position
  if (buttonState == HIGH) {
     for(pos = myservo.read(); pos >=5; pos -= 1) { // goes from 90 degrees to 20 degrees in 1 step                                   
       myservo.write(pos);                        // tell servo to go to position in variable 'ONpos'
       timeDelay = random(15, 30);
       delay(5);                                        // randomize wait time for the servo to reach the position
     }
  }
  else {
     timeDelay = random(1, 4);
     for(pos = myservo.read(); pos <=105; pos += timeDelay) {// goes from 20 degrees to 90 degrees in 1 step                            
       myservo.write(pos);                         // tell servo to go to position in variable 'OFFpos'                
       delay(5);                                         // randomize wait time for the servo to reach the position
     }
  }
}

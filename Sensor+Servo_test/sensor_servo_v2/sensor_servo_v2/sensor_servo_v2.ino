#include <NewPing.h>    //actually worked
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

//NewPing setup of pins and maximum distance
#define TRIGGER_PIN_1 2  //left sensor
#define ECHO_PIN_1 3     //left sensor
#define TRIGGER_PIN_2 9  //right sensor
#define ECHO_PIN_2 10     //right sensor
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters).

NewPing sonarL(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);  //only two sensors for now, L and R
NewPing sonarR(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);  //until we figure out how to mount a front one
int x;
int y;

void setup() {

  servoLeft.attach(5);
  servoRight.attach(6);

}

void loop() {   //will it loop?
    x = sonarL.ping_cm();
    delay (200);      //timing?
    y = sonarR.ping_cm();
    if (x <= 10 && x != 0) {    //if ping goes over max distance 0 is returned
       // Turn right in place
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(300);             //can be shorter
    }
    else if (y <= 10 && y != 0) {
      // Turn left in place
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(300);             //left turn is too sharp. Shorter timing?
    }
    else {
      // Full speed forward
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise   //Would reducing the value decresase speed?
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(600);         //likewise, may need shorter timing to reduce offset
    }
}

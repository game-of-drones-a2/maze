#include <NewPing.h>
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

//NewPing setup of pins and maximum distance
#define TRIGGER_PIN_1 4  //left sensor    change sensor pins
#define ECHO_PIN_1 5     //left sensor
#define TRIGGER_PIN_2 8  //right sensor
#define ECHO_PIN_2 9     //right sensor
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters).

NewPing sonarL(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonarR(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
int x;
int y;

void setup() {
  //Serial.begin(115200);   //Note: not exactly necessary w/out serial output

  servoLeft.attach(10);   //change pins to 5 and 6
  servoRight.attach(11);  //check tape for which one is right servo

}

void loop() {
    x = sonarL.ping_cm();
    delay (200);
    y = sonarR.ping_cm();
    if (x <= 10) {
       // Turn right in place
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(600); 
    }
    else if (y <= 10) {
      // Turn left in place
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(600);
    }
    else {
      // Full speed forward
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(1000);
    }
}

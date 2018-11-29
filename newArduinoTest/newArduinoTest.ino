#include <Servo.h>

Servo servoLeft;                             // Declare left and right servos
Servo servoRight;

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(3);                      // Attach left signal to pin 3
  servoRight.attach(5);                     // Attach right signal to pin 5
  // Full speed forward
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(2000);                               // ...for 2 seconds
}

void loop() {
  // put your main code here, to run repeatedly:

}

//void SonarSensor

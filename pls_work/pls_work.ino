<<<<<<< HEAD
// Robotics with the BOE Shield - ForwardLeftRightBackward
// Move forward, left, right, then backward for testing and tuning.

#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left and right servos
Servo servoRight;
 
void setup()                                 // Built-in initialization block
{
  servoLeft.attach(5);                      // Attach left signal to pin 3
  servoRight.attach(6);                     // Attach right signal to pin 2

  // Full speed forward
  //servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(2000);                               // ...for 2 seconds

  // Turn left in place
  //servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(600);                                // ...for 0.6 seconds

  // Turn right in place
  //servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(600);                                // ...for 0.6 seconds

  // Full speed backward
  //servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(2000);                               // ...for 2 seconds

  //servoLeft.detach();                        // Stop sending servo signals]
  servoRight.detach();
}  

void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
=======
// Robotics with the BOE Shield - ForwardLeftRightBackward
// Move forward, left, right, then backward for testing and tuning.

#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left and right servos
Servo servoRight;
 
void setup()                                 // Built-in initialization block
{
  servoLeft.attach(5);                      // Attach left signal to pin 3
  servoRight.attach(6);                     // Attach right signal to pin 2

  // Full speed forward
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(2000);                               // ...for 2 seconds

  // Turn left in place
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(600);                                // ...for 0.6 seconds

  // Turn right in place
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(600);                                // ...for 0.6 seconds

  // Full speed backward
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(2000);                               // ...for 2 seconds

  servoLeft.detach();                        // Stop sending servo signals]
  servoRight.detach();
}  

void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
>>>>>>> 003566440ba48e1888482c88c6862917a8deaa8f
}

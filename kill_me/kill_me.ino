#include <NewPing.h>
//#include <Servo.h>

//Servo servoLeft;
//Servo servoRight;

//NewPing setup of pins and maximum distance
#define TRIGGER_PIN_1 2  //left sensor
#define ECHO_PIN_1 3     //left sensor
#define TRIGGER_PIN_2 9  //right sensor
#define ECHO_PIN_2 10     //right sensor
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters).

NewPing sonarL(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonarR(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
int x;
int y;

void setup() {
  Serial.begin(9600);   //Note: not exactly necessary w/out serial output

  //servoLeft.attach(10);
  //servoRight.attach(11);

}

void loop() {
    delay (200);
    x = sonarL.ping_cm();
    delay (200);
    y = sonarR.ping_cm();
     if (x <= 10 && x != 0){
    Serial.print("left ");
    }
    if (y <= 10 && y != 0) {
  Serial.print("right ");
    }
    
}

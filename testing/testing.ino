#include <NewPing.h>              //Testing sensors with analog pins in conjunction with digital
//#include <Servo.h>              //Works just fine

//Servo servoLeft;
//Servo servoRight;

//NewPing setup of pins and maximum distance
#define TRIGGER_PIN_1 4  //left sensor
#define ECHO_PIN_1 3     //left sensor
#define TRIGGER_PIN_2 A0  //right sensor      ANALOG
#define ECHO_PIN_2 A1     //right sensor      ANALOG
#define TRIGGER_PIN_3 8   //middle sensor
#define ECHO_PIN_3 7      //middle sensor
#define MAX_DISTANCE 50 // Maximum distance we want to ping for (in centimeters).

NewPing sonarL(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonarR(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonarM(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
int x, y, z;

void setup() {
  Serial.begin(9600);   //Note: not exactly necessary w/out serial output

  //servoLeft.attach(5);
  //servoRight.attach(6);

}

void loop() {

  // 'Half' speed forward
  //servoLeft.writeMicroseconds(1650);         // Left wheel counterclockwise
  //servoRight.writeMicroseconds(1430);        // Right wheel clockwise
    while (true){
    delay (200);
    x = sonarL.ping_cm();
    if (x <= 10 && x != 0){
    Serial.print("left ");
    }
    delay (200);
    y = sonarR.ping_cm();       //analog   
    if (y <= 10 && y != 0) {
  Serial.print("right ");
    }
    delay (200);
    z = sonarM.ping_cm();
    if (z <= 10 && z != 0) {
  Serial.print("middle ");
    }
    }
    
}

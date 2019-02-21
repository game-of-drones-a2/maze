// includes
#include <NewPing.h>
//#include <SoftwareSerial.h>
#include <PID_v1.h>
#include <Servo.h>

// ********* CONSTANTS *********

// SPEED OF ROBOT for going straight
#define DEFAULT_LEFT_SPEED 1650
#define MAX_LEFT_SPEED 1700
#define MIN_LEFT_SPEED 1550

#define DEFAULT_RIGHT_SPEED 1430
#define MAX_RIGHT_SPEED 1300
#define MIN_RIGHT_SPEED 1450

#define MAX_DISTANCE 70 // max distance that sonar detects in cm
#define MAX_WALL_DISTANCE 15
#define END_DISTANCE 30
#define CLOSE_DISTANCE 5 // this is just in case of emergency

#define LEFT 0
#define RIGHT 1
#define FRONT 2
#define BACK 3

#define SONAR_NUM 3

// ********** PINS *********
// BUTTONS
const int button_start = 2; // INTERRUPT PINS: 2, 3

// SERVOS
const int servo_left = 5; // PWM 10
const int servo_right = 6; // PWM 11

// USONIC
const int usonic_left_trigger = 4; // 4; -- was 4 before
const int usonic_left_echo = 3; // 3;  -- was 3 before
const int usonic_right_trigger = A0; // 9;
const int usonic_right_echo = A1; // 9;
const int usonic_front_trigger = 8; // 8;
const int usonic_front_echo = 7; //7;

// LEDs
const int led_left = A4;  // A5;
const int led_right = A3; // A4;
const int led_front = A5; // A3;


// ********** VARIABLES - make them private if possible **********
// Start and End
int interrupt;
int round_number;
int pause;

// Letters
String letter_list;
int letter_index;
char direction_letter;
char direction_letter_old;

// Servos
Servo servoLeft;
Servo servoRight;
int servo_pwm[2];
int servo_pwm_old[2];

// USONIC
NewPing sonar[SONAR_NUM] = { // NewPing object array
  NewPing(usonic_left_trigger, usonic_left_echo, MAX_DISTANCE),
  NewPing(usonic_right_trigger, usonic_right_echo, MAX_DISTANCE),
  NewPing(usonic_front_trigger, usonic_front_echo, MAX_DISTANCE)
};
int distance[3];

// Controllers
double Setpoint, Input, Output;
//Specify the links and initial tuning parameters
double Kp = 2, Ki = 5, Kd = 1;
PID bumpingPID(&Input, &Output, &Setpoint, Kp, 0, 0, DIRECT);
PID offsetPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
PID anglePID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
PID forwardPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// ********** INITIALISATION *********
void setup() {
  Serial.begin(9600);

  // LEDs
  pinMode(led_left, OUTPUT);
  pinMode(led_right, OUTPUT);
  pinMode(led_front, OUTPUT);

  // SPEED INIT
  servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;

  // Initialise variables
  // direction_letter = 'A';
  // letter_list;
  direction_letter_old = 'X'; // needs to be initialised with X
  letter_index = 0; // should be set to 0
  pause = 1; // should be set to 1
  interrupt = 0; // should be set to 0
  round_number = 0; // should be set to 0

  // START BUTTON
  // tutorial: attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
  pinMode(button_start, INPUT); // or INPUT_PULLUP or INPUT_PULLDOWN
  attachInterrupt(digitalPinToInterrupt(button_start), button_start_maze_pressed, HIGH); // or use CHANGE

}

// ********* MAIN ROUTINE **********
void loop() {

  if (interrupt == 1) {
    round_number ++;
    Serial.print("button pressed ");
    Serial.println(round_number);
    pause = 0;
    if (round_number == 2) {
      transfer_table();
    }
    start_maze();
    interrupt = 0;
  }
  if (pause == 1) {
    // do nothing
    delay(500);
  } else {
    // get data of all the three usonic sensors
    three_usonics();
    Serial.println(distance[LEFT]);
    Serial.println(distance[FRONT]);
    Serial.println(distance[RIGHT]);
    Serial.println(" ---- ");
    direction_letter = analyse_where_to_go_1(distance); // different in number 2 !?

    // ********* SET SERVO VALUES *********
    if ((close_wall(distance[LEFT]) == true) || (close_wall(distance[FRONT]) == true) || (close_wall(distance[RIGHT]) == true)) {
      // if any wall is too close: correct
      correct_bumping(); // emergency case
    } else {
      // if direction changes
      if (direction_letter_old != direction_letter) {
        Serial.print(direction_letter);
        if (direction_letter != 'A') {
          set_letter(direction_letter);
        }
        set_servo_values();
        direction_letter_old = direction_letter;
      }
    }

    // ********* SET SERVOS *********
    if (servo_pwm[LEFT] != servo_pwm_old[LEFT] || servo_pwm[RIGHT] != servo_pwm_old[RIGHT]) {
      // if either of them has changed
      set_servos();
      servo_pwm_old[LEFT] = servo_pwm[LEFT];
      servo_pwm_old[RIGHT] = servo_pwm[RIGHT];
    }
  }
}

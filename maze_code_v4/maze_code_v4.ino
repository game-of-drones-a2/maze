/*
 *  Maze Solving Robot
 *  2018/2019
 *  Christina Bornberg, Alex Bruczkowski
 *
 *  Hardware components in this project:
 *  - 3 LEDs
 *  - 2 servos (Parallax Continuous Rotation Servo)
 *  - 3 usonic sensors (HC-SR04)
 *  - 1 push button
 *  - resistors, decoupling capacitors
*/

// ********* INCLUDES *********
#include <NewPing.h>
#include <PID_v1.h>
#include <Servo.h>

// ********* CONSTANTS *********

// SPEED OF ROBOT for going straight
#define DEFAULT_LEFT_SPEED 1650
#define MAX_LEFT_SPEED 1700
#define MIN_LEFT_SPEED 1550

#define DEFAULT_STOP_SPEED 1500

#define DEFAULT_RIGHT_SPEED 1430
#define MAX_RIGHT_SPEED 1300
#define MIN_RIGHT_SPEED 1450

// DISTANCES - USONIC SENSOR
#define MAX_DISTANCE 70 // max distance that sonar detects in cm
#define MAX_WALL_DISTANCE 15 // maybe 20 ?!
#define END_DISTANCE 40
#define CLOSE_DISTANCE 3 // this is just in case of emergency

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
const int usonic_left_trigger = A3; // 4; -- was 4 before
const int usonic_left_echo = A4; // 3;  -- was 3 before
const int usonic_right_trigger = 3; // 9;
const int usonic_right_echo = 4; // 9;
const int usonic_front_trigger = 8; // 8;
const int usonic_front_echo = 7; //7;

// LEDs
const int led_left = A2;  // A5; (GREEN)
const int led_right = 9; // A3; (RED)
const int led_front = A5; // A4; (YELLOW)

// ********** VARIABLES - make them private if possible **********
// Start and End
int interrupt;
int round_number;
int pause;

// Letters
String letter_list;
String letter_list_2;
char letter_list_letter;
int letter_index;
char direction_letter;
char direction_letter_old;
char check_letter;

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
double setpoint, input, output, ahead_max_distance;
int offset;

//Specify the links and initial tuning parameters
double kp = 1, ki = 0.05, kd = 0.25;
double much_kp = 3, much_ki = 0.2, much_kd = 1; // kp was 4 before

PID offset_pid(&input, &output, &setpoint, kp, ki, kd, DIRECT);
// PID offset_pid_right(&input_right, &output_right, &setpoint, kp, ki, kd, DIRECT);
// PID anglePID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
// PID forwardPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

// ********** INITIALISATION *********
void setup() {
  //Serial.begin(9600);
  Serial.begin(115200);

  // Controller for correction
  offset_pid.SetMode(AUTOMATIC);

  // LEDs
  pinMode(led_left, OUTPUT);
  pinMode(led_right, OUTPUT);
  pinMode(led_front, OUTPUT);

  // START BUTTON: attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
  pinMode(button_start, INPUT); // or INPUT_PULLUP or INPUT_PULLDOWN
  attachInterrupt(digitalPinToInterrupt(button_start), button_start_maze_pressed, HIGH); // or use CHANGE

  // SPEED INIT
  servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;

  // Initialise variables
  direction_letter = 'A';
  // letter_list;
  direction_letter_old = 'X'; // needs to be initialised with X
  check_letter = 'X';
  letter_index = 0; // should be set to 0
  pause = 1; // should be set to 1
  interrupt = 0; // should be set to 0
  round_number = 0; // should be set to 0

  // testing
  // testing_routines();
}

// ********* MAIN ROUTINE **********
void loop() {

  if (interrupt == 1) {
    start_maze();
    interrupt = 0;
  }
  if (pause == 1) {
    // do nothing
    delay(500);
  } else {
    // ********** GET DATA OF USONIC **********
    three_usonics();
    print_distances();
    // ********* FIND OUT WHERE TO GO *********
    if (direction_letter != 'B') {
      direction_letter = analyse_where_to_go(distance); // different in number 2 !?
      while (check_letter != direction_letter) {
        // need to get 2 same letters to react, makes the system more robust
        three_usonics();
        direction_letter = analyse_where_to_go(distance); // different in number 2 !?
        check_letter = direction_letter;
      }
    } else {
      if (wall(distance[FRONT]) == false) { // no wall
        direction_letter = 'A';
      }
    }
    if (round_number > 1) {
      print_letters();
      direction_letter = compare_letters(direction_letter);
      print_letters();
    }
    if (direction_letter == 'A') {
      correct_offset();
    }
    // ********* SET SERVO VALUES *********
    if ((close_wall(distance[LEFT]) == true) || (close_wall(distance[FRONT]) == true) || (close_wall(distance[RIGHT]) == true)) {
      // if any wall is too close: correct
      correct_bumping(); // emergency case
      direction_letter_old = 'C';
    } else {
      // if direction changes
      if (direction_letter_old != direction_letter) {
        if (direction_letter != 'A') {
          set_letter(direction_letter); // just in 1st round TODO
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
    // printing_routines();
  }
}

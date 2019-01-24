// includes
#include <NewPing.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

// variables - try to put them to functions - global is always bad

String letter_list;
char direction_letter;
int round_number;
int distance_L_R_F[3];
int pause;

// SPEED OF ROBOT
#define DEFAULT_LEFT_SPEED 1700
#define DEFAULT_RIGHT_SPEED 1420
#define DEFAULT_DELAY 100
int left_delay_right[3];

// set ports
// BUTTONS
const int button_start = 2; // INTERRUPT
// const int button_end = 3; // INTERRUPT

// SERVOS
const int servo_left = 5; // PWM 10
const int servo_right = 6; // PWM 11


// USONIC
const int usonic_left_trigger = 4; // 4; -- was 2 before
const int usonic_left_echo = 3; // 5;
const int usonic_middle_trigger = 8; // 6;
const int usonic_middle_echo = 7; //7;
const int usonic_right_trigger = 9;
const int usonic_right_echo = 10; // 9;

// LEDs
const int led_left = A5;
const int led_right = A4;
const int led_front = A3;

int letter_index;

#define MAX_DISTANCE 100 // max distance that sonar detects in cm
#define SONAR_NUM 3

#define MAX_WALL_DISTANCE 20
#define END_DISTANCE 50
#define CLOSE_DISTANCE 5

#define LEFT 0
#define STRAIGHT 1
#define DELAY 1
#define RIGHT 2
#define BACK 3

NewPing sonar[SONAR_NUM] = { // NewPing object array
  NewPing(usonic_left_trigger, usonic_left_echo, MAX_DISTANCE),
  NewPing(usonic_middle_trigger, usonic_middle_echo, MAX_DISTANCE),
  NewPing(usonic_right_trigger, usonic_right_echo, MAX_DISTANCE)
};

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // need that for usonic newPing

  // LEDs
  pinMode(led_left, OUTPUT);
  pinMode(led_right, OUTPUT);
  pinMode(led_front, OUTPUT);

  // SERVOS
  servoLeft.attach(servo_left);
  servoRight.attach(servo_right);

  // SPEED
  left_delay_right[0] = DEFAULT_LEFT_SPEED;
  left_delay_right[1] = DEFAULT_DELAY;
  left_delay_right[2] = DEFAULT_RIGHT_SPEED;

  // initialisation of variables
  direction_letter = 'X';
  letter_list = String('X');
  letter_index = 0;
  round_number = 0; // should be set to zero
  pause = 1; // should be 1

  // START BUTTON
  // can attatch interrupt with: attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
  // pinMode(button_start, INPUT); // or INPUT_PULLUP or INPUT_PULLDOWN
  // attachInterrupt(digitalPinToInterrupt(button_start), button_start_maze_pressed, RISING); // or use CHANGE

  button_start_maze_pressed();
  //start_maze();

}

void loop() {
  // put your main code here, to run repeatedly

  if (pause == 1) {
    // do nothing
  } else {

    // get data of all the three usonic sensors
    three_usonics(); 

    if (round_number == 1) {
      // round one
      direction_letter = analyse_where_to_go_1(distance_L_R_F);
      if (direction_letter != 'A') {
        set_letter(direction_letter);
      }
    } else if (round_number > 1) {
      // round two or higher
      if(direction_letter != 'A'){
        direction_letter = get_letter();
        letter_index ++;
        // if no letter is available = end of maze
      }
      direction_letter = analyse_where_to_go_2(distance_L_R_F, direction_letter);
    }

    Serial.print(direction_letter);

    // File: servos_go_to.ino
    // perhaps do that in another therad, so it doesn't stop for every measurement
    switch (direction_letter) {
      case 'A': go_ahead(); break; // go ahead, when nothing else
      case 'L': go_left(); break; // turn about 90deg
      case 'R': go_right(); break; // turn about 90deg
      case 'S': go_straight(round_number); break; // go straight: when no right wall in 1 round, when no left wall in second round
      case 'B': go_back(); break; // turn about 180deg
      case 'P': go_pause(); break; // end of the maze
      default: Serial.println("Nothing to do"); break;
    }
  }
}


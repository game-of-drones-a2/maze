// includes
#include <NewPing.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

// variables - try to put them to functions - global is always bad

String letter_list;
char direction_letter;
char last_direction_letter;
int round_number;
int distance_L_R_F[3];
int pause;
int interrupt;

// DELAY with millis()
// https://canvas.instructure.com/courses/1054116/pages/arduino-millis-and-simpletimer-instead-of-delay-and-blocking
#define DELAY_AHEAD 100
#define DELAY_LEFT 100
#define DELAY_STRAIGH 100
#define DELAY_RIGHT 100
#define DELAY_BACK 100
#define DELAY_DEFAULT 100
#define DELAY_CORRECT 5
unsigned long delay_time = DELAY_DEFAULT;
unsigned long current_time;
unsigned long last_time;

// SPEED OF ROBOT
#define DEFAULT_LEFT_SPEED 1700
#define DEFAULT_RIGHT_SPEED 1420
#define DEFAULT_DELAY 100
int left_delay_right[3];

// set ports
// BUTTONS
const int button_start = 2; // INTERRUPT

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
const int led_left = A5; // green
const int led_right = A4; //
const int led_front = A3;

int letter_index;
char list_letter;
char usonic_letter;

#define MAX_DISTANCE 70 // max distance that sonar detects in cm
#define SONAR_NUM 3

#define MAX_WALL_DISTANCE 15
#define END_DISTANCE 30
#define CLOSE_DISTANCE 10

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

  // SPEED
  left_delay_right[0] = DEFAULT_LEFT_SPEED;
  left_delay_right[1] = DEFAULT_DELAY;
  left_delay_right[2] = DEFAULT_RIGHT_SPEED;

  // DELAY with millis()
  current_time = millis();
  last_time = current_time;

  // Initialise variables
  // direction_letter = 'X';
  // letter_list;
  last_direction_letter = 'X';
  letter_index = 0;
  pause = 1; // should be set to 1
  interrupt = 0;
  round_number = 0; // should be set to 0

  // START BUTTON
  // can attatch interrupt with: attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
  pinMode(button_start, INPUT); // or INPUT_PULLUP or INPUT_PULLDOWN
  attachInterrupt(digitalPinToInterrupt(button_start), button_start_maze_pressed, HIGH); // or use CHANGE
  
}

void loop() {
  // put your main code here, to run repeatedly

  if (interrupt == 1){
    round_number ++;
    Serial.print("button pressed ");
    Serial.println(round_number);
    pause = 0;
    if(round_number == 2){
      transfer_table();
    }
    // SERVOS
    servoLeft.attach(servo_left);
    servoRight.attach(servo_right);

    delay(500);
        
    start_maze(); // is working
    interrupt = 0;
  }
  if (pause == 1) {
    // do nothing
  } else {
    // get data of all the three usonic sensors
    three_usonics(); 
    direction_letter = analyse_where_to_go_1(distance_L_R_F);
    
    // Serial.print(direction_letter);

    // File: servos_go_to.ino
    // perhaps do that in another therad, so it doesn't stop for every measurement
    if (last_direction_letter != direction_letter){
      if (direction_letter != 'A') {
        set_letter(direction_letter);
      }      
        last_direction_letter = direction_letter;
        switch (direction_letter) {
          case 'P': go_pause(); break; // end of the maze
          case 'C': go_correct(); break; // need to correct
          case 'L': go_left(); break; // turn about 90deg
          case 'S': go_straight(round_number); break; // go straight: when no right wall in 1 round, when no left wall in second round
          case 'A': go_ahead(); break; // go ahead, when nothing else
          case 'R': go_right(); break; // turn about 90deg
          case 'B': go_back(); break; // turn about 180deg
          default: Serial.println("Nothing to do"); break;
        }  
        
    }   
  }
}


// includes
#include <NewPing.h>
#include <SoftwareSerial.h>
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

// variables - try to put them to functions - global is always bad
String letter_list;
char direction_letter;
int round_number; // probably we don't need that
int distance_L_R_F[3]; 
int pause;

#define DEFAULT_LEFT_SPEED 1700
#define DEFAULT_RIGHT_SPEED 1420
int left_speed;
int right_speed;

// set ports
// BUTTONS
// const int button_start = 2; // INTERRUPT
// const int button_end = 3; // INTERRUPT
// SERVOS
const int servo_left = 5; // PWM 10
const int servo_right = 6; // PWM 11


// USONIC
const int usonic_left_trigger = 2; // 4;
const int usonic_left_echo = 3; // 5;
const int usonic_middle_trigger = 9; // 6;
const int usonic_middle_echo = 10; //7;
const int usonic_right_trigger = 8;
const int usonic_right_echo = 7; // 9;

const int led_left = A5;
const int led_right = A4;

#define MAX_DISTANCE 100 // max distance in cm
#define SONAR_NUM 3

#define MAX_WALL_DISTANCE 30

#define LEFT 0
#define STRAIGHT 1
#define RIGHT 2
#define BACK 3

NewPing sonar[SONAR_NUM] = { // NewPing object array
  NewPing(usonic_left_trigger, usonic_left_echo, MAX_DISTANCE),
  NewPing(usonic_middle_trigger, usonic_middle_echo, MAX_DISTANCE),
  NewPing(usonic_right_trigger, usonic_right_echo, MAX_DISTANCE)
};

/* PROTYPES -- need that??? */
int get_usonic_data(NewPing sonar);


// use for other serial
// SoftwareSerial serial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // need that for usonic newPing

  pinMode(led_left, OUTPUT);
  pinMode(led_right, OUTPUT);

  servoLeft.attach(servo_left);
  servoRight.attach(servo_right);

  left_speed = DEFAULT_LEFT_SPEED;
  right_speed = DEFAULT_RIGHT_SPEED;

  // initialisation of variables
  direction_letter = 'X';
  letter_list = String('X');
  round_number = 0;
  pause = 1;

  // buttons with interrupt
  //attachInterrupt(digitalPinToInterrupt(pin), ISR, mode); // (recommended)
//  pinMode(button_start, INPUT); // or INPUT_PULLUP or INPUT_PULLDOWN
  //attachInterrupt(digitalPinToInterrupt(button_start), read_button_start, RISING); // or use CHANGE
//  pinMode(button_end, INPUT);
  //attachInterrupt(digitalPinToInterrupt(button_end), read_button_end, RISING); // or use CHANGE
}

void loop() {

  
  
  // put your main code here, to run repeatedly:
  // create files with the functions for each:

  //while(pause == 1){
    // wait
  ////}

  //digitalWrite(led_pin2, HIGH);
  //digitalWrite(led_pin, HIGH);
/*
  three_usonics(); // get data of all the three usonic sensors
 
  if (round_number == 1){
    direction_letter = analyse_where_to_go_1(distance_L_R_F);
    if(direction_letter != 'A'){
      set_letter(direction_letter); 
    }
  }else{
    if(direction_letter != 'A'){
      direction_letter = get_letter(); 
    }
    direction_letter = analyse_where_to_go_2(distance_L_R_F, direction_letter);
  }

  // File: servos.ino
  // perhaps do that in another therad, so it doesn't stop for every measurement
  switch (direction_letter){
    case 'A': go_ahead(distance_L_R_F); break; // go ahead, when nothing else
    case 'L': go_left(); break; // turn about 90deg
    case 'R': go_right(); break; // turn about 90deg
    case 'S': go_straight(round_number); break; // go straight: when no right wall in 1 round, when no left wall in second round
    case 'B': go_back(); break; // turn about 180deg
    default: Serial.println("Nothing to do"); break;
  }
  
  if(FALSE){ // when end is reached
    go_stop();
    servoLeft.detach();
    servoRight.detach();
  }
*/
}


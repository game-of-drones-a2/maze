// note: every round, higher than 1 is called round 2

// includes
#include <NewPing.h>

// variables - try to put them to functions - global is always bad
String letter_list;
char direction_letter;
int round_number; // probably we don't need that
int distance_L_R_F[3]; 
int pause;

// set ports
// BUTTONS
const int button_start = 2; // INTERRUPT
const int button_end = 3; // INTERRUPT
// SERVOS
const int servo_left = 10; // PWM
const int servo_right = 11; // PWM
// USONIC
const int usonic_left_trigger = 4;
const int usonic_left_echo = 5;
const int usonic_middle_trigger = 6;
const int usonic_middle_echo = 7;
const int usonic_right_trigger = 8;
const int usonic_right_echo = 9;

#DEFINE MAX_DISTANCE 40 // max distance in cm
#DEFINE SONAR_NUM 3

NewPing sonar[SONAR_NUM] = { // NewPing object array
  NewPing(usonic_left_trigger, usonic_left_echo, MAX_DISTANCE),
  NewPing(usonic_middle_trigger, usonic_middle_echo, MAX_DISTANCE),
  NewPing(usonic_right_trigger, usonic_right_echo, MAX_DISTANCE)
}

void setup() {
  // put your setup code here, to run once:
  direction_letter = 'X';
  letter_list = String('X');
  round_number = 0;
  pause = 1;

  Serial.begin(115200); // need that for usonic newPing

  // buttons, are working at interrupt
  //attachInterrupt(digitalPinToInterrupt(pin), ISR, mode); // (recommended)
  pinMode(button_start, INPUT); // or INPUT_PULLUP or INPUT_PULLDOWN
  attachInterrupt(digitalPinToInterrupt(button_start), read_button_start, RISING); // or use CHANGE
  pinMode(button_end, INPUT);
  attachInterrupt(digitalPinToInterrupt(button_end), read_button_end, RISING); // or use CHANGE
}

void loop() {
  // put your main code here, to run repeatedly:
  // create files with the functions for each:

  while(pause == 1){
    // wait
  }

  // could do that in loop + put NewPing objects to array
  for(int i = 0; i < SONAR_NUM; i++){
      distance_L_R_F[i] = get_usonic_data(sonar[i]);
  }
 
  if (round_number == 1){
    direction_letter = analyse_where_to_go(distance_L_R_F);
    set_letter(direction_letter);
  }else{
    direction_letter = get_letter();
  }

  // File: servos.ino
  switch (direction_letter){
    case 'L': go_left(); break; // turn about 90deg
    case 'R': go_right(); break; // turn about 90deg
    case 'S': go_straight(); break; // go straight until xxx - different for 2nd round
    case 'B': go_back(); break; // turn about 180deg
    default: Serial.println("Nothing to do"); break;
  }
  improve_position(distance_L_R_F); // eventually put that into go_straight
  // when turning, try to not crash a wall TODO: function

}

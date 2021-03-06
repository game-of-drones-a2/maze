/*
    Maze Solving Robot
    2018/2019
    Christina Bornberg, Alex Bruczkowski

    Initialisation for round 2+
    reset letter list 2
    tell robot, that a new round has started
    if round is 2, the transfer table is used to simplify the path

*/

// ********** CALLED BY THE INTERRUPT FROM BUTTON ********
void button_start_maze_pressed () {
  delay(1000); // for debouncing
  interrupt = 1;
}

// ********** START THE MAZE **********
// Go ahead, as long as no wall is detected
// this needs to be done in all rounds
// no letter is saved here
// this is working
void start_maze() {
  // LED
  //blink(1, 1, 1);
  letter_list_2 = "";
  letter.index = 0;
  round_number ++;
  Serial.print("button pressed ");
  Serial.println(round_number);
  pause = 0;
  // INITIALISATION ROUND 2
  if (round_number == 2) {
    transfer_table();
    letter.list = get_letter();
    letter.index++;
    Serial.println(letter_list);
  }
  // SERVOS
  servoLeft.attach(servo_left);
  servoRight.attach(servo_right);
  Serial.println("attach");
  delay(500);
  servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
  set_servos();
  while (true) {
    three_usonics();
    print_distances();
    if (no_wall(distance[LEFT]) == false || no_wall(distance[FRONT]) == false || no_wall(distance[RIGHT]) == false) { 
      // if there is any wall detected
      if (no_wall(distance[LEFT]) == false && no_wall(distance[RIGHT]) == false){
        ahead_max_distance = distance[LEFT] + distance[RIGHT];
        distance_ahead[LEFT] = distance[LEFT];
        distance_ahead[RIGHT] = distance[RIGHT];
      }else{
        ahead_max_distance = DEFAULT_STEADY_DISTANCE;
        distance_ahead[LEFT] = DEFAULT_STEADY_DISTANCE/2;
        distance_ahead[RIGHT] = DEFAULT_STEADY_DISTANCE/2;
      }
      break;
    }
  }
}

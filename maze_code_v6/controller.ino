/*
    Maze Solving Robot
    2018/2019
    Christina Bornberg, Alex Bruczkowski

    Error is the difference between set point and actual point

*/

// ********** EMERGENCY **********
// avoid bumping, if any wall is close
// FIND VALUES HERE
// eventually get go left, go right here
// changed it here, maybe while instead of if is better
// TODO: find out if "if" or "else if" is better
void correct_bumping() {
  // just use a P controller
  while (close_wall(distance[LEFT]) == true && close_wall(distance[FRONT]) == true){
    Serial.println("Correct");
    servo_pwm[LEFT] = 1650;
    servo_pwm[RIGHT] = 1400;
    set_servos();
  }
  while (close_wall(distance[FRONT]) == true && close_wall(distance[RIGHT]) == true){
    Serial.println("Correct");
    servo_pwm[LEFT] = 1350;
    servo_pwm[RIGHT] = 1600;
    set_servos();
    three_usonics();
  }
  while (close_wall(distance[LEFT]) == true) {
    Serial.println("Correct");
    servo_pwm[LEFT] = 1550;
    servo_pwm[RIGHT] = 1550;
    set_servos();
    three_usonics();
  }
  while (close_wall(distance[FRONT]) == true) {
    Serial.println("Correct");
    servo_pwm[LEFT] = 1450;
    servo_pwm[RIGHT] = 1550;
    set_servos();
    three_usonics();
  }
  while (close_wall(distance[RIGHT]) == true) {
    Serial.println("Correct");
    servo_pwm[LEFT] = 1450;
    servo_pwm[RIGHT] = 1450;
    set_servos();
    three_usonics();
  }
}

// ********** PID GO AHEAD **********
void correct_offset() {

  // make system more robust
  if (distance[RIGHT] > END_DISTANCE && distance[LEFT] > END_DISTANCE && distance[RIGHT] != 0 && distance[LEFT] != 0) {
    ahead_max_distance = (distance[RIGHT] + distance[LEFT]);
  }
  distance_ahead[LEFT] = distance[LEFT];
  distance_ahead[RIGHT] = distance[RIGHT];
  setpoint = ahead_max_distance / 2;
  offset = ahead_max_distance / 3; // was /3 before

  if (distance[LEFT] > distance[RIGHT]) {
    input = distance[RIGHT];
  } else input = distance[LEFT];

  controller_mapping(distance[LEFT], distance[RIGHT]); // needs to be [LEFT], [RIGHT]
}

// ********** PID GO STRAIGHT (1st round) **********
// ahead_max_distance comes from last time, two walls were detected
void correct_straight_left_wall() {
  setpoint = ahead_max_distance / 2;
  offset = ahead_max_distance / 3;
  input = distance[LEFT];

  // TODO: need to test that
  controller_mapping(distance[LEFT], setpoint);

}

// ********** PID GO STRAIGHT (2nd+ round) **********
// ahead_max_distance comes from last time, two walls were detected
void correct_straight_right_wall() {
  setpoint = ahead_max_distance / 2;
  offset = ahead_max_distance / 3;
  input = distance[RIGHT];

  // TODO: need to test that
  controller_mapping(distance[RIGHT], setpoint);

}

// ********** MAPPING PID OUTPUT TO PWM **********
void controller_mapping(int distance1, int distance2) {

  int output_left;
  int output_right;
  double errorP;

  errorP = abs(distance1 - distance2);
  print_errorP_and_offset(errorP);

  if (errorP <= offset) { // just need little change
    pid_ctrl.SetTunings(kp, ki, kd);
  } else { // need to change a lot
    pid_ctrl.SetTunings(much_kp, much_ki, much_kd);
  }

  pid_ctrl.Compute();

  if (distance1 > distance2 + offset) { // go to the left
    output_left = map(output, 0, ahead_max_distance, DEFAULT_LEFT_SPEED, DEFAULT_STOP_SPEED);
    output_right = map(output, 0, ahead_max_distance, DEFAULT_STOP_SPEED, DEFAULT_RIGHT_SPEED);
  } else if (distance2 > distance1 + offset) { // go to the right
    output_left = map(output, 0, ahead_max_distance, DEFAULT_STOP_SPEED, DEFAULT_LEFT_SPEED);
    output_right = map(output, 0, ahead_max_distance, DEFAULT_RIGHT_SPEED, DEFAULT_STOP_SPEED);
  } else { // within offset, go straight
    output_left = DEFAULT_LEFT_SPEED; // map(output, 0, max_distance, 1650, DEFAULT_STOP_SPEED);
    output_right = DEFAULT_RIGHT_SPEED; // map(output, 0, max_distance, 1430, DEFAULT_STOP_SPEED);
  }

  // print_outputs(output_left, output_right);

  servo_pwm[LEFT] = output_left;
  servo_pwm[RIGHT] = output_right;
}

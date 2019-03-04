// Error is the difference between set point and actual point

// ********** EMERGENCY **********
// avoid bumping, if any wall is close
// FIND VALUES HERE
// eventually get go left, go right here
// changed it here, maybe while instead of if is better
// TODO: find out if "if" or "else if" is better
void correct_bumping() {
  // just use a P controller
  if (close_wall(distance[LEFT]) == true) {
    servo_pwm[LEFT] = 1550;
    servo_pwm[RIGHT] = 1550;
  }
  if (close_wall(distance[FRONT]) == true) {
    servo_pwm[LEFT] = 1300;
    servo_pwm[RIGHT] = 1600;//1570;
  }
  if (close_wall(distance[RIGHT]) == true) {
    servo_pwm[LEFT] = 1460;
    servo_pwm[RIGHT] = 1460;
  }
}

// use PID to be in the middle while go_ahead()
void correct_offset() {

  ahead_max_distance = (distance[RIGHT] + distance[LEFT]);
  setpoint = ahead_max_distance / 2;
  offset = ahead_max_distance / 3; // was /3 before

  if (distance[LEFT] > distance[RIGHT]) {
    input = distance[RIGHT];
  } else input = distance[LEFT];

  controller_mapping(distance[LEFT], distance[RIGHT]); // beeds to be [LEFT], [RIGHT]

}

void correct_straight_left_wall() {

  int max_distance = ahead_max_distance;
  setpoint = max_distance / 2;
  offset = max_distance / 4;

  input = distance[LEFT];
  // errorP = abs(distance[LEFT] - setpoint);

  // TODO: need to test that
  controller_mapping(distance[LEFT], setpoint);

}

void correct_straight_right_wall() {

  int max_distance = ahead_max_distance;
  setpoint = max_distance / 2;
  offset = max_distance / 4;

  input = distance[RIGHT];

  // TODO: need to test that
  controller_mapping(distance[RIGHT], setpoint);

}


// use PID to correct the angle while go_ahead()
void correct_angle() {

}

// use PID to go faster in second round
// for N, M, R - we can calucalte error in the front and go faster (1st round)
void correct_forward() {

}


void controller_mapping(int distance1, int distance2) {

  int output_left;
  int output_right;
  double errorP;

  errorP = abs(distance1 - distance2);
  // errorP = abs(distance[RIGHT] - setpoint);
  // print_errorP_and_offset(errorP);

  if (errorP <= offset) { // just need little change
    offset_pid.SetTunings(kp, 0, kd);
  } else { // need to change a lot
    offset_pid.SetTunings(much_kp, 0, much_kd);
  }

  offset_pid.Compute();

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

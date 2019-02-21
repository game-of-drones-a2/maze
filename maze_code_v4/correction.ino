// Error is the difference between set point and actual point

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
    servo_pwm[RIGHT] = 1570;
  }
  if (close_wall(distance[RIGHT]) == true) {
    servo_pwm[LEFT] = 1460;
    servo_pwm[RIGHT] = 1460;
  }
}


// use PID to be in the middle while go_ahead()
void correct_offset() {

}

// use PID to correct the angle while go_ahead()
void correct_angle() {

}

// use PID to go faster in second round
// for N, M, R - we can calucalte error in the front and go faster
void correct_forward() {

}

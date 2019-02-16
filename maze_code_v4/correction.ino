// Error is the difference between set point and actual point

// avoid bumping, if any wall is close
void correct_bumping() {

    // just use a P controller

}

// FIND VALUES HERE
// eventually get go left, go right here
// changed it here, maybe while instead of if is better
// TODO: find out if "if" or "else if" is better
void go_correct() {
  if (close_wall(distance[LEFT]) == true) {
    set_servos(1540, 1540, 5); // turn a bit right    change to 1550 1550?
  }

  if (close_wall(distance[STRAIGHT]) == true) {
    set_servos(1300, 1570, 500);
  }

  if (close_wall(distance[RIGHT]) == true) {
    set_servos(1460, 1460, 5); // turn a bit left
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

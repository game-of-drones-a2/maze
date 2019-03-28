/*
    Maze Solving Robot
    2018/2019
    Christina Bornberg, Alex Bruczkowski

    Smooth Turning
    
*/

void turning_left() {
  double o;
  int output_left = 1500, output_right = 1500;

  o = distance_ahead[LEFT];
  output_left = 1550; // map(o, 1, 500, 1550, 1650); // PIVOT, STRAIGHT
  output_right = 1400; // map(o, 1, 500, 1400, 1350); // PIVOT, STRAIGHT
  servo_pwm[LEFT] = output_left;
  servo_pwm[RIGHT] = output_right;
}

void turning_right() {
  double o;
  int output_left = 1500, output_right = 1500;

  o = distance_ahead[RIGHT];
  output_left = 1650; // map(o, 1, 500, 1600, 1650); // PIVOT, STRAIGHT
  output_right = 1480; // map(o, 1, 500, 1450, 1350);
  // output_right = map(o, 1, 50, 1350, 1550);
  // higher number first for going right as far as I understand
  servo_pwm[LEFT] = output_left;
  servo_pwm[RIGHT] = output_right;
}

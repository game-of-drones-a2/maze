void turning_left() {

  double o;
  int output_left, output_right;

  o = distance[LEFT];

  output_left = map(o, 1, 70, 1550, 1650);
  output_right = 1350;

  servo_pwm[LEFT] = output_left;
  servo_pwm[RIGHT] = output_right;


}


void turning_right() {

  double o;
  int output_left, output_right;

  o = distance[RIGHT];

  output_left = 1650;
  output_right = map(o, 1, 70, 1450, 1350);
  // higher number first for going right as far as I understand

  servo_pwm[LEFT] = output_left;
  servo_pwm[RIGHT] = output_right;

}

// working with the servos here
// perhaps we need to get new sensor data here as well, as we

/* INITIAL VALUES
  go straight - left: 1700, right: 1420
  go left -
  go right -
  go back - left: 1700, right: 1700, delay: 1100
  go pause - left: 1500 right: 1500
*/

// when changing all values, we might make while instead of do while(true)
// 1st: sensors, 2nd: break condition, 3rd: go
// sensor is done in algorithm (be aware!)

void set_servos() {
  servoLeft.writeMicroseconds(servo_pwm[LEFT]);
  servoRight.writeMicroseconds(servo_pwm[RIGHT]);
  delay(5);
}

void set_servo_values_round_1() {
  switch (direction_letter) {
    case 'A': set_ahead(); break; // go ahead, when nothing else
    case 'L': set_left(); break; // turn about 90deg
    case 'M': set_left(); break;
    case 'N': set_left(); break;
    case 'S': set_straight(round_number); break; // go straight: when no right wall in 1 round, when no left wall in second round
    case 'R': set_right(); break; // turn about 90deg
    case 'B': set_back(); break; // turn about 180deg
    case 'P': set_pause(); break; // end of the maze
    default: Serial.println("Nothing to do"); break;
  }
}

void set_left() {    //need to feed values less than 1500
  blink(1, 1, 0);
  servo_pwm[LEFT] = 1550; //DEFAULT_RIGHT_SPEED;
  servo_pwm[RIGHT] = 1400; //DEFAULT_RIGHT_SPEED;
}

// go straight, until a wall is detected (1st round 'R', second round 'L')
void set_straight(int round_number) {
  blink(0, 1, 1);
  if (round_number == 1) {
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
  } else if (round_number > 1) {
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
  }
}

void set_ahead() {
  blink(0, 1, 0);
  servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
}

void set_right() { //To do: adjust values to turn sharper
  blink(0, 0, 1);
 // if (round_number = 1) {
    servo_pwm[LEFT] = 1650; // DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = 1480; //DEFAULT_LEFT_SPEED;
 /* } else {
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_LEFT_SPEED;
    correct_forward(); // TODO
  }*/
}

void set_back() {
  blink(0, 0, 0);
  servo_pwm[LEFT] = MAX_LEFT_SPEED;
  servo_pwm[RIGHT] = MAX_LEFT_SPEED;
}

// end
void set_pause() {
  pause = 1;
  servoLeft.detach();
  servoRight.detach();
  blink(0, 0, 0);
  delay(1000);
  blink(1, 0, 0);
  delay(1000);
  blink(0, 1, 0);
  delay(1000);
  blink(0, 0, 1);
  delay(1000);
  blink(1, 1, 1);
}

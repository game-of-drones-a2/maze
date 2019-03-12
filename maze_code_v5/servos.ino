/*
    Maze Solving Robot
    2018/2019
    Christina Bornberg, Alex Bruczkowski

    working with servos here

    INITIAL VALUES
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
}

void set_servo_values() {
  switch (direction_letter) {
    case 'A': blink(0, 1, 0); set_ahead(); break; // go ahead, when nothing else
    case 'L': blink(1, 1, 0); set_left(); break; // turn about 90deg
    case 'M': blink(1, 0, 1); set_left(); break;
    case 'N': blink(1, 0, 0); set_left(); break;
    case 'S': blink(0, 1, 1); set_straight(round_number); break; // go straight: when no right wall in 1 round, when no left wall in second round
    case 'R': blink(0, 0, 1); set_right(); break; // turn about 90deg
    case 'B': blink(0, 0, 0); set_back(); break; // turn about 180deg
    case 'P': set_pause(); break; // end of the maze
    default: Serial.println("Nothing to do"); break;
  }
}

// ********* LEFT *********
//need to feed values less than 1500
void set_left() {
  servo_pwm[LEFT] = 1550; //DEFAULT_RIGHT_SPEED;
  servo_pwm[RIGHT] = 1400; //DEFAULT_RIGHT_SPEED;
}

// ********* STRAIGHT **********
// go straight, until a wall is detected (1st round 'R', second round 'L')
void set_straight(int round_number) { 
  if (round_number == 1) {
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
  } else if (round_number > 1) {
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
  }
}

// ********* STRAIGHT AHEAD *********
void set_ahead() {
  servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
}

// ********* RIGHT *********
//To do: adjust values to turn sharper
void set_right() {
  // if (round_number = 1) {
  servo_pwm[LEFT] = 1650; // DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = 1480; //DEFAULT_LEFT_SPEED;
  /* } else {
     servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
     servo_pwm[RIGHT] = DEFAULT_LEFT_SPEED;
     correct_forward(); // TODO
    }*/
}

// ********* 180 deg turn **********
void set_back() {
  servo_pwm[LEFT] = MAX_LEFT_SPEED;
  servo_pwm[RIGHT] = MAX_LEFT_SPEED;
}

// ********* STOP, END OF MAZE*********
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

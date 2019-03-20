/*
    Maze Solving Robot
    2018/2019
    Christina Bornberg, Alex Bruczkowski

    working with servos here
    due to controllers, we don't need that perfect values for ahead and straight

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
  servoRight.writeMicroseconds((int)servo_pwm[RIGHT]+servo_pwm[RIGHT]/15);
  servo_pwm_old[LEFT] = servo_pwm[LEFT];
  servo_pwm_old[RIGHT] = servo_pwm[RIGHT];
  print_servo_values();
}

void set_servo_values() {
  switch (letter.dir) {
    case 'A': blink(0, 1, 0); set_straight(); break; // go ahead, when nothing else
    case 'L': blink(1, 1, 0); set_left(); break; // turn about 90deg
    case 'M': blink(1, 0, 1); set_left(); break;
    case 'N': blink(1, 0, 0); set_left(); break;
    case 'S': blink(0, 1, 1); set_straight(); break; // go straight: when no right wall in 1 round, when no left wall in second round
    case 'R': blink(0, 0, 1); set_right(); break; // turn about 90deg
    case 'B': blink(0, 0, 0); set_back(); break; // turn about 180deg
    case 'P': set_pause(); break; // end of the maze
    default: Serial.println("Nothing to do"); break;
  }
}

// ********* LEFT SMOOTH TURN *********
//need to feed values less than 1500
void set_left() {
  servo_pwm[LEFT] = DLEFT_SLEFT; //DEFAULT_RIGHT_SPEED;
  servo_pwm[RIGHT] = DLEFT_SRIGHT; //DEFAULT_RIGHT_SPEED;
}

// ********* RIGHT SMOOTH TURN *********
//To do: adjust values to turn sharper
void set_right() {
  servo_pwm[LEFT] = DRIGHT_SLEFT; // DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DRIGHT_SRIGHT; //DEFAULT_LEFT_SPEED;
}

// ********* STRAIGHT **********
// go straight, until a wall is detected (1st round 'R', second round 'L')
void set_straight() { 
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
}

// ********* BACK 180 deg spin turn **********
void set_back() {
  servo_pwm[LEFT] = 1700;
  servo_pwm[RIGHT] = 1700;
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

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

void set_servos(){
  servoLeft.writeMicroseconds(servo_pwm[LEFT]);
  servoRight.writeMicroseconds(servo_pwm[RIGHT]);
  delay(5);
}

void go_left(){     //need to feed values less than 1500
  blink(1,1,0);
  servo_pwm[LEFT] = DEFAULT_RIGHT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
}

// go straight, until a wall is detected (1st round 'R', second round 'L')
void go_straight(int round_number){
  blink(0,1,1);
  if(round_number == 1){
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;  
  }else if(round_number > 1){
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED; 
  }
}

void go_ahead(){
  blink(0,1,0);
  servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;
}

void go_right(){  //need to feed values greater tgan 1500
  blink(0,0,1);
  if(round_number = 1){
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_LEFT_SPEED;  
  }else{
    servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
    servo_pwm[RIGHT] = DEFAULT_LEFT_SPEED;  
    correct_forward(); // TODO
  }
}

void go_back(){
  blink(0,0,0);
  servo_pwm[LEFT] = DEFAULT_RIGHT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED;  
}

// end
void go_pause(){
  round_number ++;
  pause = 1;
  servoLeft.detach();
  servoRight.detach();
  blink(0,0,0);
  delay(500);
  blink(1,0,0);
  delay(500);
  blink(0,1,0);
  delay(500);
  blink(0,0,1);
  delay(500);
  blink(1,1,1);
}

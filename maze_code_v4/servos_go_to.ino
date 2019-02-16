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

void set_servos(int speed_left, int speed_right){
  servoLeft.writeMicroseconds(speed_left);
  servoRight.writeMicroseconds(speed_right);
  delay(5);
}

void go_left(){ 
  blink(1,1,0);
  set_servos(1400, 1400); // turn a bit left
}

void go_left_m(){
  blink(1,0,1);
  if(round_number = 1){
    set_servos(1400, 1400);  
  }else{
    correct_forward();
  }
}

void go_left_n(){
  blink(1,0,0);
  if(round_number = 1){
    set_servos(1400, 1400);  
  }else{
    correct_forward();
  }
}

// go straight, until a wall is detected (1st round 'R', second round 'L')
void go_straight(int round_number){
  blink(0,1,1);
  if(round_number == 1){
    set_servos(1650, 1430);  
  }else if(round_number > 1){
      set_servos(1650, 1430);  
  }
}

void go_ahead(){
  blink(0,1,0);
  set_servos(1650, 1430);
}

void go_right(){
  blink(0,0,1);
  if(round_number = 1){
    set_servos(1600, 1600);  
  }else{
    correct_forward();
  }
}

void go_back(){
  blink(0,0,0);
  set_servos(1700, 1700);
}

// end
void go_pause(){
  set_servos(1500, 1500);
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

// working with the servos here
// perhaps we need to get new sensor data here as well, as we 

/* INITIAL VALUES
go straight - left: 1700, right: 1420
go left - 
go right -
go back - 

*/

void go(int speed_left, int speed_right, int delay_time){
  servoLeft.writeMicroseconds(speed_left);
  servoRight.writeMicroseconds(speed_right);
  delay(delay_time);
}

void go_left(){ 
  blink(1,0,0);
  go(1700, 1420, 300); // go a bit to the front
  do{
    go(1300, 1300, 250); // turn a bit left
    go(1700, 1420, 300); // go a bit to the front 
    three_usonics();
  }while(no_wall(distance_L_R_F[LEFT]));
}

void go_right(){
  blink(0,1,0);
  go(1700, 1420, 300); // go a bit to the front
  do{
    go(1700, 1700, 250); // turn a bit left
    go(1700, 1420, 300); // go a bit to the front
    three_usonics();
  }while(no_wall(distance_L_R_F[RIGHT]));
}

// go straight, until a wall is detected (1st round 'R', second round 'L')
void go_straight(int round_number){
  blink(0,0,1);
  //do{
  //go_correct(1700, 1420);
  go(1700, 1420, 100);  
 //}while(no_wall(distance_L_R_F[RIGHT]));
}

void go_back(){
  blink(0,0,0);
  go(1700, 1700, 1100);  
}

void go_stop(){
  go(1500, 1500, 100);
  blink(0,0,0);
  delay(500);
  blink(1,1,0);
  delay(500);
  blink(0,0,0);
  delay(500);
  blink(1,1,0);

  // servoLeft.detach();
  // servoRight.detach();
}

void go_ahead(){
  blink(1,1,1);
  //go_correct(1700, 1420);
  go(1700, 1420, 100);
}

void go_correct(int l_speed, int r_speed){
  while(close_wall(distance_L_R_F[LEFT]) == true){
    l_speed += 5;
    r_speed -= 5;  
    go(l_speed, r_speed, 100);
  }
  while(close_wall(distance_L_R_F[RIGHT]) == true){
    r_speed += 5;  
    l_speed -= 5;
    go(l_speed, r_speed, 100);
  }
}



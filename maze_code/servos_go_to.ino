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
  blink(1,0);
  go(1700, 1420, 100); // go a bit to the front
  do{
    go(1300, 1300, 250); // turn a bit left
    go(1700, 1420, 100); // go a bit to the front 
    three_usonics();
  }while(distance_L_R_F[LEFT] > 20 || distance_L_R_F[LEFT] == 0);
  blink(0,0); 
  //go(1500, 1500, 100);
}

void go_right(){
  blink(0,1);
  go(1700, 1420, 100); // go a bit to the front
  do{
    go(1700, 1700, 250); // turn a bit left
    go(1700, 1420, 100); // go a bit to the front
    three_usonics();
  }while(distance_L_R_F[RIGHT] > 20 || distance_L_R_F[RIGHT] == 0);
  blink(0,0); 
  //go(1500, 1500, 100); // = stop
}

// go straight, until a wall is detected (1st round 'R', second round 'L')
void go_straight(int round_number){
  blink(1,1);
  go(1700, 1420, 100);
}

void go_back(){
  blink(0,0);
  //go(1, 1, 100);  
}

void go_stop(){
  blink(0,0);
  go(1500, 1500, 100);
}

void go_ahead(int distance_L_R_F[SONAR_NUM]){
  blink(0,0);
  go(1700, 1420, 100);

}





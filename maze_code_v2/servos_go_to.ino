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

void go(int speed_left, int speed_right, int delay_time){
  servoLeft.writeMicroseconds(speed_left);
  servoRight.writeMicroseconds(speed_right);
  delay(delay_time);
}

void go_left(){ 
  blink(1,0,0);
  go(1700, 1420, 300); // go a bit to the front
  do{
    go_correct();
    go(1300, 1300, 250); // turn a bit left
    go(1700, 1420, 300); // go a bit to the front 
    three_usonics();
  }while(no_wall(distance_L_R_F[LEFT]));
}

void go_right(){
  blink(0,1,0);
  go(1700, 1420, 300); // go a bit to the front
  do{
    go_correct();
    go(1700, 1700, 250); // turn a bit right
    go(1700, 1420, 300); // go a bit to the front
    three_usonics();
  }while(no_wall(distance_L_R_F[RIGHT]));
}

// go straight, until a wall is detected (1st round 'R', second round 'L')
void go_straight(int round_number){
  blink(0,0,1);
  if(round_number == 1){
      do{
      go_correct();
      go(1700, 1420, 100);  
      three_usonics();
      if(no_wall(distance_L_R_F[LEFT])) break; // somewhere else!!!!!
    }while(no_wall(distance_L_R_F[RIGHT])); // ???? TODO
  }else if(round_number > 1){
      do{
      go_correct();
      go(1700, 1420, 100);  
      three_usonics();
      }while(no_wall(distance_L_R_F[LEFT]));  
  }
}

void go_back(){
  blink(0,0,0);
  do{
    go_correct(); // maybe
    go(1700, 1700, 1100);
    three_usonics();
  }while(no_wall(distance_L_R_F[STRAIGHT]));
}

void go_pause(){
  go(1500, 1500, 100);
  round_number ++;
  pause = 1;
  servoLeft.detach();
  servoRight.detach();
  blink(0,0,0);
  delay(500);
  blink(1,1,0);
  delay(500);
  blink(0,0,0);
  delay(500);
  blink(1,1,0);
}

void go_ahead(){
  blink(1,1,1);
  go_correct();
  go(1700, 1420, 100);
}

// FIND VALUES HERE
// eventually get go left, go right here
// changed it here, maybe while instead of if is better
// TODO: find out if "if" or "else if" is better
void go_correct(){
<<<<<<< HEAD
 while(close_wall(distance_L_R_F[LEFT]) == true){
   // if((left_delay_right[LEFT] - 50) > 1500){ //previously -50
      left_delay_right[LEFT] -= 0;
    //}
    //if((left_delay_right[RIGHT] + 50) < 1700){  //previously +50
      left_delay_right[RIGHT] += 180; 
    //}  
    go(left_delay_right[LEFT], left_delay_right[RIGHT], left_delay_right[DELAY]);
    three_usonics();
  }
  while(close_wall(distance_L_R_F[RIGHT]) == true){
    left_delay_right[LEFT] += 5;
    left_delay_right[RIGHT] -= 5;  
    go(left_delay_right[LEFT], left_delay_right[RIGHT], left_delay_right[DELAY]);
    three_usonics();
  }
  while(close_wall(distance_L_R_F[STRAIGHT]) == true){
    go(100, 100, 100);
=======
  while (close_wall(distance_L_R_F[LEFT]) || close_wall(distance_L_R_F[RIGHT]) || close_wall(distance_L_R_F[STRAIGHT])){
>>>>>>> 54029b89a3dc061aeedbf5de62d0f495077762e6
    three_usonics();
    if (close_wall(distance_L_R_F[RIGHT]) == true){   
      go(1520, 1520, 5); // turn a bit right    change to 1550 1550? 
    }else if (close_wall(distance_L_R_F[RIGHT]) == true){
      go(1470, 1470, 5); // turn a bit left  
    }else if(close_wall(distance_L_R_F[STRAIGHT]) == true){
      go(1300, 1580, 100);
    }
  }
}

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

void set_servos(int speed_left, int speed_right, int delay_time){
  servoLeft.writeMicroseconds(speed_left);
  servoRight.writeMicroseconds(speed_right);
  delay(5);
}

void go_left(){ 
  blink(1,0,0);
 // do{
    // set_servos(1700, 1420, 300); // go a bit to the front 
    set_servos(1400, 1400, 250); // turn a bit left
   // three_usonics();
 // }while(no_wall(distance_L_R_F[LEFT]));
}

// go straight, until a wall is detected (1st round 'R', second round 'L')
void go_straight(int round_number){
  blink(0,0,1);
  if(round_number == 1){
    //  do{
      set_servos(1650, 1430, 100);  
     // three_usonics();
      //if(no_wall(distance_L_R_F[LEFT])) break; // somewhere else!!!!!
    //}while(no_wall(distance_L_R_F[RIGHT])); // ???? TODO
  }else if(round_number > 1){
      //do{
      set_servos(1650, 1430, 100);  
     // three_usonics();
      //}while(no_wall(distance_L_R_F[LEFT]));  
  }
}

void go_right(){
  blink(0,1,0);
  //do{
    set_servos(1600, 1600, 250); // turn a bit right
    // three_usonics();
  //}while(no_wall(distance_L_R_F[RIGHT]));
}

void go_back(){
  blink(0,0,0);
  //do{
    //go_correct(); // maybe
    set_servos(1700, 1700, 1100);
    //three_usonics();
  //}while(no_wall(distance_L_R_F[STRAIGHT]));
}

void go_pause(){
  set_servos(1500, 1500, 100);
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
  set_servos(1650, 1430, 100);
}

// FIND VALUES HERE
// eventually get go left, go right here
// changed it here, maybe while instead of if is better
// TODO: find out if "if" or "else if" is better
void go_correct(){
//  while (close_wall(distance_L_R_F[LEFT]) || close_wall(distance_L_R_F[RIGHT]) || close_wall(distance_L_R_F[STRAIGHT])){
//    three_usonics();
    if (close_wall(distance_L_R_F[LEFT]) == true){   
      set_servos(1540, 1540, 5); // turn a bit right    change to 1550 1550? 
    }
    if (close_wall(distance_L_R_F[RIGHT]) == true){
      set_servos(1460, 1460, 5); // turn a bit left  
    }
    if(close_wall(distance_L_R_F[STRAIGHT]) == true){
      set_servos(1300, 1570, 500);
    }
  //}
}



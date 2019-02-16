// tell robot, that a new round has started
// if round is 2, the transfer table is used to simplify the path
void button_start_maze_pressed (){
  delay(1000); // for debouncing
  interrupt = 1;
}

// ********** START THE MAZE **********
// Go ahead, as long as no wall is detected
// this needs to be done in all rounds
// no letter is saved here
// this is working
// set_servos(1650, 1430);
void start_maze(){
  
  // SERVOS
  servoLeft.attach(servo_left);
  servoRight.attach(servo_right);
  delay(500);

  blink(1,1,1);
  servo_pwm[LEFT] = DEFAULT_LEFT_SPEED;
  servo_pwm[RIGHT] = DEFAULT_RIGHT_SPEED; 
  set_servos();
  while(true){
    three_usonics();
    if (wall(distance[LEFT]) || wall(distance[FRONT]) || wall(distance[RIGHT])){
      // if there is any wall detected
      break;
    }
  }
}

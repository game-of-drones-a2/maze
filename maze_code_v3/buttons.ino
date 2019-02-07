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
void start_maze(){
  while(true){
    three_usonics();
    if ( (no_wall(distance_L_R_F[LEFT]) == false) || (no_wall(distance_L_R_F[STRAIGHT]) == false) || (no_wall(distance_L_R_F[RIGHT]) == false) ){
      // if there is any wall detected
      break;
    }
    go_ahead();
    delay(DELAY_AHEAD);
  }
}


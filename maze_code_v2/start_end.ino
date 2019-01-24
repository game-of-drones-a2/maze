// ********** START THE MAZE **********
// Go ahead, as long as no wall is detected
// this needs to be done in all rounds
// no letter is saved here
// this is working
void start_maze(){
  Serial.println("Start");
  do{
    three_usonics();
    if ( (no_wall(distance_L_R_F[LEFT]) == false) || (no_wall(distance_L_R_F[STRAIGHT]) == false) || (no_wall(distance_L_R_F[RIGHT]) == false) ){
      break;
    }
    go_ahead();
  }while(true);
}


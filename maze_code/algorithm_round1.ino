// algorithm file for round 1
// nothing with servos / sensors here


char analyse_where_to_go_1(int distance_L_R_F[SONAR_NUM]){
  
  if(distance_L_R_F[LEFT] > MAX_WALL_DISTANCE || distance_L_R_F[LEFT] == 0){
      return 'L';
  } else if(distance_L_R_F[STRAIGHT] > MAX_WALL_DISTANCE || distance_L_R_F[STRAIGHT] == 0){
      if(distance_L_R_F[RIGHT] > MAX_WALL_DISTANCE || distance_L_R_F[RIGHT] == 0){
        return 'S';
      }
      return 'A';
  } else if(distance_L_R_F[RIGHT] > MAX_WALL_DISTANCE || distance_L_R_F[RIGHT] == 0){
      return 'R';  
  } else return 'B'; 
}

void set_letter (char direction_letter){ // is it like append? test that func!
  //if(direction_letter != 'A'){
    letter_list.setCharAt(letter_list.length(), direction_letter); 
  //}
}


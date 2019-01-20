// algorithm file for round 1
// nothing with servos / sensors here

char analyse_where_to_go_1(int distance_L_R_F[SONAR_NUM]){

  if ( (no_wall(distance_L_R_F[LEFT]) == true) && (no_wall(distance_L_R_F[STRAIGHT]) == true) && (no_wall(distance_L_R_F[RIGHT]) == true) ){
      return 'E'; // end of maze
  } else 
  if(no_wall(distance_L_R_F[LEFT]) == true){
      return 'L';
  } else if(no_wall(distance_L_R_F[STRAIGHT]) == true){
      if(no_wall(distance_L_R_F[RIGHT])== true){
        return 'S'; // one time, until wall is detected TODO
      }
      return 'A';
  } else if(no_wall(distance_L_R_F[RIGHT]) == true){
      return 'R';  
  } else return 'B'; 
}

void set_letter (char direction_letter){ // is it like append? test that func!
  //if(direction_letter != 'A'){
    letter_list.setCharAt(letter_list.length(), direction_letter); 
  //}
}


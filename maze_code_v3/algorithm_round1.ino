// algorithm file for round 1
// nothing with servos / sensors here

char analyse_where_to_go_1(int distance_L_R_F[SONAR_NUM]){
  if ( (end_wall(distance_L_R_F[LEFT]) == true) && (end_wall(distance_L_R_F[STRAIGHT]) == true) && (end_wall(distance_L_R_F[RIGHT]) == true) ){
      return 'P'; // end of maze = pause
  } else if ((close_wall(distance_L_R_F[LEFT]) == true) || (close_wall(distance_L_R_F[STRAIGHT]) == true) || (close_wall(distance_L_R_F[RIGHT]) == true)){
      return 'C';
  } else if(no_wall(distance_L_R_F[LEFT]) == true){
      return 'L';
  } else if(no_wall(distance_L_R_F[STRAIGHT]) == true){
      if(no_wall(distance_L_R_F[RIGHT])== true){
        return 'S'; // one time, until wall is detected TODO: done
      }
      return 'A';
  } else if(no_wall(distance_L_R_F[RIGHT]) == true){
      return 'R';  
  } else return 'B'; 
}

void set_letter (char direction_letter){ // is it like append? test that func!
    letter_list.concat(direction_letter); 
    Serial.println("Letterlist: " + letter_list);
}


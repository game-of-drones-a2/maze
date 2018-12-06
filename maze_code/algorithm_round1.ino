// algorithm file for round 1
// nothing with servos / sensors here

// do something with "as long as whatever, go straight"
// analyse the data of usonic here
char analyse_where_to_go_1(int distance_L_R_F[SONAR_NUM]){
  
  if(distance_L_R_F[0] > 30 || distance_L_R_F[0] == 0){ // left
      return 'L';
  } else if(distance_L_R_F[1] > 30 || distance_L_R_F[1] == 0){
      if(distance_L_R_F[2] > 30 || distance_L_R_F[2] == 0){
        return 'S';
      }
      return 'A';
  } else if(distance_L_R_F[2] > 30 || distance_L_R_F[2] == 0){
      return 'R';  
  } else {
      return 'B'; 
  }
}

void set_letter (char direction_letter){ // is it like append? test that func!
  letter_list.setCharAt(letter_list.length(), direction_letter);
}

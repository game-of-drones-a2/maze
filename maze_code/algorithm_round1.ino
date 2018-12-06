// algorithm file for round 1
// nothing with servos / sensors here

// do something with "as long as whatever, go straight"
// analyse the data of usonic here
char analyse_where_to_go(int distance_L_R_F[SONAR_NUM]){
  
  if(distance_L_R_F[0] > 30){ // left
      return 'L';
  } else if(distance_L_R_F[1] > 30){
      return 'S'; 
  } else if(distance_L_R_F[1] > 30){
      return 'R';  
  } else if(distance_L_R_F[1] > 30){
      return 'B'; 
  } else {
    Serial.println("ERROR with letters in analyse_where_to_go");
  }
     
    
    
}

void set_letter (char direction_letter){ // is it like append? test that func!
  letter_list.setCharAt(letter_list.length(), direction_letter);
}

// algorithm file for round 2
// nothing with servos / sensors here

char analyse_where_to_go_2(int distance[SONAR_NUM], char letter) {
// WRONG !!!!!
  /* LETTER L */
  if (letter == 'L') {
    if (wall(distance[LEFT]) == true) {
      return 'L';
    } else return 'A';
  /* LETTER S */
  } else if (letter == 'S') {
    if (wall(distance[FRONT]) == true) {
      if (wall(distance[RIGHT]) == true) {
        return 'S';
      } else {
        return 'A';
      }
    } else return 'A'; // maybe dangerous
   /* LETTER R */
  } else if (letter == 'R') {
    if (wall(distance[LEFT]) == true) {
      return 'R';
    } else return 'A';
  } else return 'A'; // was A before
  
}

char get_letter () {
  return (letter_list.charAt(letter_index));
}

// called when interrupt start button and second round
void transfer_table () {
  char transfer_letter = 'X';
  letter_index = letter_list.length();
  int counter = 0;
  while (letter_list.length() > counter) { 
    //Serial.print(counter);
    //Serial.println(letter_list.charAt(counter));
    if (letter_list.charAt(counter) == 'B') {
      Serial.println(counter);
      transfer_letter = get_transfer_letter(letter_list.charAt(counter - 1), letter_list.charAt(counter + 1));
      Serial.println(transfer_letter);
      letter_list.replace(letter_list.substring(counter - 1, counter + 2), String(transfer_letter));
      Serial.println(letter_list);
      Serial.println("Substring");
      Serial.println(letter_list.substring(counter - 1, counter + 1));
      //if (transfer_letter = 'B') counter --;
      counter --;
      counter --;
    }else{
      // counter ++;
    }
    counter ++;
  }
  Serial.println("Letter list");
  Serial.println(letter_list);
  Serial.println("Letter list end");
}

// called in function transfer_table()
char get_transfer_letter(char dec, char inc) {
  // letter in the middle is always "B"
  char transf = 'X';

  if (dec == 'L') {
    switch (inc) {
      case ('L'): transf = 'S'; break;
      case ('R'): transf = 'B'; break;
      case ('S'): transf = 'R'; break;
      default: Serial.println("There is a problem L"); break;
    }
  }
  else if (dec == 'R') {
    switch (inc) {
      case ('L'): transf = 'B'; break;
      case ('R'): transf = 'S'; break;
      case ('S'): transf = 'L'; break;
      default: Serial.println("There is a problem R"); break;
    }
  }
  else if (dec == 'S') {
    switch (inc) {
      case ('L'): transf = 'R'; break;
      case ('R'): transf = 'L'; break;
      case ('S'): transf = 'B'; break;
      default: Serial.println("There is a problem S"); break;
    }
  } else {
    Serial.println("There is a problem xxxx");
  }

  // Serial.print(dec);
  // Serial.println(inc);

  return transf;
}

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
  while (letter_list.length() > counter) { // eventually, while not end or i-- at some point
    //Serial.prin
    if (letter_list.charAt(counter) == 'B') {
      transfer_letter = get_transfer_letter(counter - 1, counter + 1);
      letter_list.replace(letter_list.substring(counter - 1, counter + 1), String(transfer_letter));
      Serial.print("Substring: ");
      Serial.print(transfer_letter);
      if (transfer_letter == 'B') {
        counter = counter - 2; // or not?!
      }
    }
    counter ++;
  }
  Serial.println("Letter list");
  Serial.print(letter_list);
}

// called in function transfer_table()
char get_transfer_letter(char dec, char inc) {
  // letter in the middle is always "B"
  char transf = 'X';

  if (dec = 'L') {
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
  return transf;
}

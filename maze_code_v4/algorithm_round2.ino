// algorithm file for round 2
// nothing with servos / sensors here

char analyse_where_to_go_2(int distance[SONAR_NUM], char letter) {

  /* LETTER L */
  if (letter == 'L') {
    if (no_wall(distance[LEFT]) == true) {
      return 'L';
    } else return 'A';
  /* LETTER S */
  } else if (letter == 'S') {
    if (no_wall(distance[STRAIGHT]) == true) {
      if (no_wall(distance[RIGHT]) == true) {
        return 'S';
      } else {
        return 'A';
      }
    } else return 'A'; // maybe dangerous
   /* LETTER R */
  } else if (letter == 'R') {
    if (no_wall(distance[LEFT]) == true) {
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
  int i;
  for (i = 0; i < letter_list.length(); i++) { // eventually, while not end or i-- at some point
    if (letter_list.charAt(i) == 'B') {
      transfer_letter = get_transfer_letter(i - 1, i + 1);
      letter_list.replace(letter_list.substring(i - 1, i + 1), String(transfer_letter));
      if (transfer_letter == 'B') {
        i = i - 2; // or not?!
      }
    }
  }
  Serial.println("Letter list");
  Serial.print(letter_list);
}

// called in function transfer_table()
char get_transfer_letter(char dec, char inc) {
  char transf = 'X';

  if (dec = 'L') {
    switch (inc) {
      case ('L'): transf = 'S'; break;
      case ('R'): transf = 'B'; break;
      case ('S'): transf = 'R'; break;
      default: Serial.println("There is a problem"); break;
    }
  }
  else if (dec == 'R') {
    switch (inc) {
      case ('L'): transf = 'B'; break;
      case ('R'): transf = 'S'; break;
      case ('S'): transf = 'L'; break;
      default: Serial.println("There is a problem"); break;
    }
  }
  else if (dec == 'S') {
    switch (inc) {
      case ('L'): transf = 'R'; break;
      case ('R'): transf = 'L'; break;
      case ('S'): transf = 'B'; break;
      default: Serial.println("There is a problem"); break;
    }
  } else {
    Serial.println("There is a problem");
  }
  return transf;
}

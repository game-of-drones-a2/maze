// algorithm file for round 2
// nothing with servos / sensors here

// should compare the analyse 1 letter with the letter list


char analyse_where_to_go_2(char analyse_letter, char letter_list_letter) {
  // next letter of letter_list
  // letter from analyse where to go
  // WRONG !!!
  char return_letter = 'A';
  
  /* LETTER L */
  if (analyse_letter == letter_list_letter) {
      return_letter = 'L';
  /* LETTER S */
  } else if (letter == 'S') {
    if (wall(distance[FRONT]) == true) {
      if (wall(distance[RIGHT]) == true) {
        return_letter = 'S';
      }
    } // else return 'A'; // maybe dangerous
   /* LETTER R */
  } else if (letter == 'R') {
    if (wall(distance[LEFT]) == true) {
      return_letter 'R';
    }
  } 
  return return_letter;
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
    if (letter_list.charAt(counter) == 'B') {
      transfer_letter = get_transfer_letter(letter_list.charAt(counter - 1), letter_list.charAt(counter + 1));
      letter_list.replace(letter_list.substring(counter - 1, counter + 2), String(transfer_letter));
      if (transfer_letter = 'B') counter --;
    }else{
      counter ++;
    }
  }
}

// called in function transfer_table()
// letter in the middle is always 'B'
char get_transfer_letter(char dec, char inc) {
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
  return transf;
}

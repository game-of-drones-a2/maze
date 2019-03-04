// algorithm file for round 2
// nothing with servos / sensors here

// should compare the analyse 1 letter with the letter list


char analyse_where_to_go_2(char analyse_letter) { // second one - call by address, find out how TODO
  // analyse letter = letter from sensors
  // letter list letter = letter that was tracked in the first round
  // next letter of letter_list
  // letter from analyse where to go
  // WRONG !!!

  char return_letter = 'A';

  if (analyse_letter == letter_list_letter) {
    return_letter = analyse_letter;
  } else if (analyse_letter == 'L' && letter_list_letter == 'S') {
    return_letter = 'S';
  } else if (analyse_letter == 'S' && letter_list_letter == 'R') {
    return_letter = 'R';
  } else if (analyse_letter == 'M' && letter_list_letter == 'R') {
    return_letter = 'R';
  }

  if(return_letter == 'N' || return_letter == 'M'){
    return_letter == 'L';
  }
  if (return_letter != 'A' && letter_list_letter != get_letter()) { // TODO or yes ?!
    letter_list_letter = get_letter();
    letter_index++;
  }

  return return_letter;
}

// redo, we need letter_index++ somewhere
char get_letter () {
  return (letter_list.charAt(letter_index));
}

// called when interrupt start button and second round
void transfer_table () {
  char transfer_letter = 'X';
  int counter = 0;
  while (letter_list.length() > counter) {
    if (letter_list.charAt(counter) == 'B') {
      transfer_letter = get_transfer_letter(letter_list.charAt(counter - 1), letter_list.charAt(counter + 1));
      letter_list.replace(letter_list.substring(counter - 1, counter + 2), String(transfer_letter));
      if (transfer_letter = 'B') counter --;
    } else {
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

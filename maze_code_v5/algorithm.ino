/*
    Maze Solving Robot
    2018/2019
    Christina Bornberg, Alex Bruczkowski

    algorithm file for round 2
    nothing with servos / sensors here
    should compare the analyse 1 letter with the letter list

*/

// ********** COMPARES LETTER FROM LIST TO ANALYSED LETTER *********
// analyse letter = letter from sensors
// letter list letter = letter that was tracked in the first round
// next letter of letter_list
// letter from analyse where to go
char compare_letters(char analyse_letter) {

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

  if (return_letter == 'N' || return_letter == 'M') {
    return_letter = 'L'; // changed!!!
  }
  Serial.println(return_letter);
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
  char transfer_letter = 'A';
  unsigned int counter = 0;
  if(letter_list.charAt(counter) == 'B'){
    // there can't be a back 'B' at the beginning
    letter_list.replace(letter_list.substring(counter), String('A'));
    counter ++;
  }
  while (letter_list.length() > counter) {
    if (letter_list.charAt(counter) == 'B') {
      if (letter_list.charAt(counter + 1) == 'B') {
        // if there are two times back in a row (this should never happen in real life!!!)
        letter_list.replace(letter_list.substring(counter, counter + 2), String('B'));
      }
      transfer_letter = get_transfer_letter(letter_list.charAt(counter - 1), letter_list.charAt(counter + 1));
      letter_list.replace(letter_list.substring(counter - 1, counter + 2), String(transfer_letter));
      if (transfer_letter == 'B') counter --; // changed
    } else {
      counter ++;
    }
  }
}

// called in function transfer_table()
// letter in the middle is always 'B'
char get_transfer_letter(char dec, char inc) {
  char transf = 'A';
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
    Serial.println("There is a problem in general");
  }
  return transf;
}

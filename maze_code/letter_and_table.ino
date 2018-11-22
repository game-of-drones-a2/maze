void save_letter (char direction_letter){ // need string?" can we use char?
  letter_list->add_string_item(direction_letter);
}

void transfer_table (){

  int i;
  for(i = 0; i < letter_list.size(); i++){ // eventually, while not end or i-- at some point
    if(letter_list(i).equals('B'){
      get_transfer_letter(i-1, i+1);
      letter_list->remove_selected_item(i-1);
      letter_list->remove_selected_item(i);
      letter_list->remove_selected_item(i+1);
      letter_list->set_string_item('transfer_letter', i-1);
      if(transfer_letter.equals('B'){
        i--; // or not?!
      }
    } 
  }
}

char get_transfer_letter(char dec, char inc){

  char transf = 'X';

  if(dec.equals('L')){
    switch(inc) {
      case ('L'): transf = 'S'; break;
      case ('R'): transf = 'B'; break;
      case ('S'): transf = 'R'; break;
      default: print("There is a problem"); break;
    }    
  }  
  else if(dec.equals('R')){
    switch(inc) {
      case ('L'): transf = 'B'; break;
      case ('R'): transf = 'S'; break;
      case ('S'): transf = 'L'; break;
      default: print("There is a problem"); break;
    }    
  }
  else if(dec.equals('S')){
    switch(inc) {
      case ('L'): transf = 'R'; break;
      case ('R'): transf = 'L'; break;
      case ('S'): transf = 'B'; break;
      default: print("There is a problem"); break;
    }    
  }else{
    print("There is a problem");
  }

  
}


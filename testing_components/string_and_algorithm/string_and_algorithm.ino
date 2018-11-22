String letter_list = String('X');

void save_letter (char direction_letter){ // need string?" can we use char?
  letter_list.setCharAt(letter_list.length(),direction_letter);
}

void transfer_table (){
  char transfer_letter = 'X';
  int i;
  for(i = 0; i < letter_list.length(); i++){ // eventually, while not end or i-- at some point
    if(letter_list.charAt(i) == 'B'){
      transfer_letter = get_transfer_letter(i-1, i+1);
      letter_list.replace(letter_list.substring(i-1, i+1), String(transfer_letter));
      if(transfer_letter == 'B'){
        i--; // or not?!
      }
    } 
  }
}

char get_transfer_letter(char dec, char inc){

  char transf = 'X';

  if(dec = 'L'){
    switch(inc) {
      case ('L'): transf = 'S'; break;
      case ('R'): transf = 'B'; break;
      case ('S'): transf = 'R'; break;
      default: Serial.println("There is a problem"); break;
    }    
  }  
  else if(dec == 'R'){
    switch(inc) {
      case ('L'): transf = 'B'; break;
      case ('R'): transf = 'S'; break;
      case ('S'): transf = 'L'; break;
      default: Serial.println("There is a problem"); break;
    }    
  }
  else if(dec == 'S'){
    switch(inc) {
      case ('L'): transf = 'R'; break;
      case ('R'): transf = 'L'; break;
      case ('S'): transf = 'B'; break;
      default: Serial.println("There is a problem"); break;
    }    
  }else{
    Serial.println("There is a problem");
  }
  return transf;
}

void setup() {
  // put your setup code here, to run once:
  //letter_list = new ArrayList("X");
  Serial.println("There is no problem");
}

void loop() {
  // put your main code here, to run repeatedly:

  void transfer_table();

  
}

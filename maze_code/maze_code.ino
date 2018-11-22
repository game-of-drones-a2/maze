// includes

// variables
char direction_letter;

// set ports



void setup() {
  // put your setup code here, to run once:
  ArrayList *letter_list = new ArrayList("X"); // X is beginning ?! or leave blank
}

void loop() {
  // put your main code here, to run repeatedly:

  // create files with the functions for each:

  // File: usonic.ino
  get_usonic_data();

  // File: 
  direction_letter = where_to_go();

  // File: go_xxx.ino
  go_left();
  go_right();
  go_straight();
  go_back();
  
  // File: letter_and_table.ino
  save_letter(direction_letter);
  

}

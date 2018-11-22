// note: every round, higher than 1 is called round 2

// includes

// variables
String letter_list;
char direction_letter;
int round_number; // probably we don't need that
int distance_L_R_F[3]; 
int pause;

// set ports


void setup() {
  // put your setup code here, to run once:
  direction_letter = 'X';
  letter_list = String('X');
  round_number = 0;
  pause = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  // create files with the functions for each:

  if(pause == 1){
    if (round_number == 2){
      transfer_table();
    }
    // wait until interrupt of start button
    pause = 0
  }

  get_usonic_data(distance_L_R_F);

  if (round_number = 1){
    direction_letter = analyse_where_to_go(distance_L_R_F);
    set_letter(direction_letter);
  }else{
    direction_letter = get_letter();
  }

  // File: servos.ino
  switch (direction_letter)
  case 'L': go_left(); break; // turn about 90deg
  case 'R': go_right(); break; // turn about 90deg
  case 'S': go_straight(); break; // go straight until xxx - different for 2nd round
  case 'B': go_back(); break; // turn about 180deg
  default: Serial.println("Nothing to do"); break;

  improve_position(int distance_L_R_F[3]); 

}

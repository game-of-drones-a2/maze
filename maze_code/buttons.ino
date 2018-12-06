// we need to define, what our buttons are exactly doing

// tell robot, that a new round has started
// if round is 2, the transfer table is used to simplify the path
void read_button_start (){
  round_number ++;
  if(round_number == 2){
    transfer_table();
  }
  pause = 0;
}


// either say stop for one round
// or do a whole reset
void read_button_end (){
  pause = 1;
}

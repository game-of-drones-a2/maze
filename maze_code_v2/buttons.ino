// we need to define, what our buttons are exactly doing

// tell robot, that a new round has started
// if round is 2, the transfer table is used to simplify the path
void button_start_maze_pressed (){
  round_number ++;
  pause = 0;
  start_maze(); // is working
  if(round_number == 2){
    transfer_table();
  }
}


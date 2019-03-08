/*
 *  Maze Solving Robot
 *  2018/2019
 *  Christina Bornberg, Alex Bruczkowski
 *  
 *  LEDs
 *  
 */

// ********* LEDs that show, where no wall is ********
void blink(int left, int front, int right){
  if(left == 1){
    digitalWrite(led_left, HIGH);  
  }else{
    digitalWrite(led_left, LOW);
  }
  if (front == 1){
    digitalWrite(led_front, HIGH);
  }else{
    digitalWrite(led_front, LOW);
  }
  if (right == 1){
    digitalWrite(led_right, HIGH);
  }else{
    digitalWrite(led_right, LOW);
  }
}

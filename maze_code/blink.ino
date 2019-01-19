void blink(int left, int right){
  if(left == 1){
    digitalWrite(led_left, HIGH);  
  }else{
    digitalWrite(led_left, LOW);
  }
  if (right == 1){
    digitalWrite(led_right, HIGH);
  }else{
    digitalWrite(led_right, LOW);
  }
  
}


void testing_routines() {
  testing_letterlist();
  // testing_leds();

}
  
void testing_letterlist(){
  letter_list = "LLBSBLLLLRSRBLLBLLRSLLLRBLRLLBLLBLLLLBRLBLLLBRRLL";
  Serial.println(letter_list);
  transfer_table();
  Serial.print(letter_list);
}

void testing_leds(){
  blink(1, 0, 0);
  delay(1000);
  blink(0, 1, 0);
  delay(1000);
  blink(0, 0, 1);
  delay(1000);
}

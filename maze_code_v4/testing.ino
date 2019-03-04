/*
 * TODO: need to just save B once
 * 
 * 
 * 
 * 
 * 
 */



void testing_routines() {
  // testing_letterlist();
  // testing_leds();

}

void testing_letterlist() {
  letter_list = "LLBSBLLLLRSRBLLBLLRSLLLRBLRLLBLLBLLLLBRLBLLLBRRLL";
  Serial.print("Test letter list: ");
  Serial.println(letter_list);
  transfer_table();
  Serial.print("Test shorten: ");
  Serial.print(letter_list);
  letter_list = ""; // working?
}

void testing_leds() {
  blink(1, 0, 0);
  delay(1000);
  blink(0, 1, 0);
  delay(1000);
  blink(0, 0, 1);
  delay(1000);
}

void print_distances() {
  Serial.println(distance[LEFT]);
  Serial.println(distance[FRONT]);
  Serial.println(distance[RIGHT]);
  Serial.println(" ---- ");
}

void print_outputs(double output_left, double output_right) {
  Serial.print(output_left);
  Serial.print(output_right);
}

void print_errorP_and_offset(double errorP) {
  Serial.println("error and offset");
  Serial.println(errorP);
  Serial.println(offset);
}

void print_letters(){
  Serial.print("Direction letter: ");
  Serial.println(direction_letter);
  Serial.print(letter_index);
}

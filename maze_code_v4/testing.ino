/*
 * TODO: need to just save B once
 * 
 * 
 */



void testing_routines() {
  testing_letterlist();
  testing_leds();

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
//  Serial.println("Distances: Left, Front, Right");
  /*Serial.print(distance[LEFT]);
  Serial.print(",");
  Serial.print(distance[FRONT]);
  Serial.print(",");
  Serial.println(distance[RIGHT]);
  // Serial.print(",");
  // Serial.println(" ---- ");
  //*/
}

void print_servo_values(){
  //Serial.println("Servo PWM data: Left, Right");
  /*Serial.print(servo_pwm[LEFT]);
  Serial.print(",");
  Serial.println(servo_pwm[RIGHT]); 
  //*/
}

void print_outputs(double output_left, double output_right) {
  /*Serial.print(output_left);
  Serial.print(output_right);
  //*/
}

void print_errorP_and_offset(double errorP) {
  //Serial.println("Controller: Error, Offset, Output");
  Serial.print(errorP);
  Serial.print(", ");
  // Serial.print(offset);
  Serial.print(servo_pwm[LEFT]);
  Serial.print(", ");
  //Serial.println(output);
  Serial.println(servo_pwm[RIGHT]);
  //*/
}

void print_letters(){
 /* Serial.print("Direction letter: ");
  Serial.println(direction_letter);
  Serial.print(letter_index);
  //*/
}

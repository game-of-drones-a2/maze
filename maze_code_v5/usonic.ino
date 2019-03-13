/*
    Maze Solving Robot
    2018/2019
    Christina Bornberg, Alex Bruczkowski

    here the usonic sensor should get 3 distances: Left, Right, Straight sensors

*/

// ********** GET DATA OF ALL USONIC SENSORS **********
void three_usonics(){
  for(int i = 0; i < SONAR_NUM; i++){
    distance[i] = get_usonic_data(sonar[i]);
  }
}

// ********** GET THE DISTANCE IN CM, FOR THE GIVEN SONAR SENSOR **********
// ping_cm: Send a ping, returns the distance in centimeters or 0 (zero) if no ping echo within set distance limit 
// delay is used, as we need to wait for all data anyways, there is nothing usefull that can be done 
// by using millis instead
int get_usonic_data(NewPing sonar){
    delay(75); // minimum 33 ms
    return sonar.ping_cm();
}

// ********** NO WALL DETECTED **********
// no wall is detected, when the distance is either bigger than MAX_WALL_DISTANCE
// or if there is no wall detected
bool wall(int distance){
  if (distance > MAX_WALL_DISTANCE || distance == 0){
    return false; // no wall
  }
  return true; // wall
}

// ********** END OF THE LABYRINTH **********
// The end of the labyrinth is reached, when there is either no wall detected = 0,
// or when the next wall is more far away than END DISTANCE
bool end_wall(int distance){
  if (distance > END_DISTANCE || distance == 0){
    return false; // no wall
  }
  return true; // wall
}

// ********** THERE IS A CLOSE WALL, NEED TO CORRECT **********
// A close wall is detected, when there is a wall, closer than CLOSE_DISTANCE
// it needs to be higher than zero
bool close_wall(int distance){
  if (distance < CLOSE_DISTANCE && distance != 0){
    return true; // close wall
  }
  return false; // no close wall
}

// algorithm file for round 1
// nothing with servos / sensors here

char analyse_where_to_go_1(int distance[SONAR_NUM]) {
  
  if ((end_wall(distance[LEFT]) == false) && (end_wall(distance[FRONT]) == false) && (end_wall(distance[RIGHT]) == false)) {
    return 'P'; // end of maze when no walls = pause
  } else if ((wall(distance[LEFT]) == false) && (wall(distance[FRONT]) == false) && (wall(distance[RIGHT]) == true)) {
    return 'L'; // left
  } else if (wall(distance[LEFT]) == false && wall(distance[FRONT]) == true && wall(distance[RIGHT]) == false) {
    return 'M'; // left
  } else if (wall(distance[LEFT]) == false && wall(distance[FRONT]) == true && wall(distance[RIGHT]) == true){
    return 'N'; // left
  } else if (wall(distance[FRONT]) == false && wall(distance[RIGHT]) == false) {
    return 'S'; // straight, wenn no wall on right side
  } else if (wall(distance[FRONT]) == false && wall(distance[RIGHT]) == true) {
    return 'A'; // straight ahead - don't save in letter list
  } else if (wall(distance[RIGHT]) == false) {
    return 'R'; // right
  } else return 'B'; // when walls in each direction
  // TODO: turn as long as !wall in front
}

void set_letter (char direction_letter) {
  letter_list.concat(direction_letter);
  Serial.println("Letterlist: " + letter_list);
}

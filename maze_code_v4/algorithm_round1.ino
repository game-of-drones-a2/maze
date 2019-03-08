/*
 *  Maze Solving Robot
 *  2018/2019
 *  Christina Bornberg, Alex Bruczkowski
 *  
 *  algorithm file for round 1
 *  nothing with servos / sensors here
 *  P: end of maze when no walls = pause
 *  L: Left
 *  M: Left
 *  N: Left
 *  S: Straight, wenn no wall on right side
 *  A: Straight ahead - don't save in letter list
 *  R: Right
 *  B: Back - turn 180deg, if there are walls in each direction
 * 
 */

// ********* FIGURE OUT IN WHICH DIRECTION ROBOT SHOULD GO *********
char analyse_where_to_go(int distance[SONAR_NUM]) {

  if ((end_wall(distance[LEFT]) == false) && (end_wall(distance[FRONT]) == false) && (end_wall(distance[RIGHT]) == false)) {
    return 'P'; // pause
  } else if (wall(distance[LEFT]) == false && wall(distance[FRONT]) == false && wall(distance[RIGHT]) == true) {
    return 'L'; // left
  } else if (wall(distance[LEFT]) == false && wall(distance[FRONT]) == true && wall(distance[RIGHT]) == false) {
    return 'M'; // left
  } else if (wall(distance[LEFT]) == false && wall(distance[FRONT]) == true && wall(distance[RIGHT]) == true) {
    return 'N'; // left
  } else if (wall(distance[FRONT]) == false && wall(distance[RIGHT]) == false) {
    return 'S'; // straight
  } else if (wall(distance[FRONT]) == false && wall(distance[RIGHT]) == true) {
    return 'A'; // straight
  } else if (wall(distance[RIGHT]) == false) {
    return 'R'; // right
  } else return 'B'; // back
}

// ********* SAVES GIVEN LETTER TO THE LETTERLIST *********
void set_letter (char direction_letter) {
  letter_list.concat(direction_letter);
  Serial.println("Letterlist: " + letter_list);
}

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
  } else if (no_wall(distance[LEFT]) && no_wall(distance[FRONT]) && expected_wall(distance[RIGHT])) {
    return 'L'; // left
  } else if (no_wall(distance[LEFT]) && expected_wall(distance[FRONT]) && no_wall(distance[RIGHT])) {
    return 'M'; // left
  } else if (no_wall(distance[LEFT]) && expected_wall(distance[FRONT]) && expected_wall(distance[RIGHT])) {
    return 'N'; // left
  } else if (no_wall(distance[FRONT]) && no_wall(distance[RIGHT])) {
    return 'S'; // straight
  } else if (expected_wall(distance[LEFT]) && expected_wall(distance[FRONT]) && expected_wall(distance[RIGHT])) {
    return 'B'; // straight
  } else if (no_wall(distance[RIGHT])) {
    return 'R'; // right
  } else return 'A'; // back
}

// ********* SAVES GIVEN LETTER TO THE LETTERLIST *********
void set_letter (char direction_letter) {
  letter_list.concat(direction_letter);
  Serial.println("Letterlist: " + letter_list);
}

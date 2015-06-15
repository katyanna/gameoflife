#include "defs.h"

int randomCellCreation(unsigned density){
  return rand() < (RAND_MAX / density) ? 1 : 0;
}

void game(unsigned width, unsigned height){
  unsigned universe[height][width];
  for_position universe[line][column] = randomCellCreation(4);
  while (1) {
    populate(width, height, universe);
    generation(width, height, universe);
    usleep(200000);
  }
}

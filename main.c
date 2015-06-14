#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define for_column_by_line for_column for_line

void game(int w, int h){
  unsigned universe[h][w];
  for_column_by_line universe[line][column] = return rand() < RAND_MAX / 5 ? 1 : 0;
  while (1) {
    show(universe, w, h);
    evolve(universe, w, h);
    usleep(200000);
  }
}

int main(){
  game(40, 40);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define for_column_by_line for_column for_line

void show(void *u, int w, int h){
  int (*universe)[w] = u;
  printf("\033[H");
  for (int line = 0; line < h; line++) {
    for (int column = 0; column < w; column++) {
    	if (universe[line][column]) {
    		printf("#");
    	} else {
    		printf("  ");
    	}
    }
    printf("\n");
  }
  fflush(stdout);
}

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

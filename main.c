#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define for_column for (int column = 0; column < w; column++)
#define for_line for (int line = 0; line < h; line++)
#define for_column_by_line for_column for_line
#define for_position for_line for_column

void show(void *u, int w, int h){
  int (*universe)[w] = u;
  printf("\033[H");
  for_line {
    for_column printf(universe[line][column] ? "#" : "  ");
    printf("\n");
  }
  fflush(stdout);
}

int nature(int currentCell, int top, int bottom, int left, int right, int topLeft, int topRight, int bottomRight, int bottomLeft){
  int living = top + bottom + left + right + topLeft + topRight + bottomRight + bottomLeft;

  if (currentCell){
    if (living <= 1 || living >= 4){
      return 0;
    }

    if (living == 2 || living == 3){
      return 1;
    }

  } else {
    if (living == 3) {
      return 1;
    } else {
      return 0;
    }
  }
}


void evolve(void *u, int w, int h){
  unsigned (*universe)[w] = u;
  unsigned new[w][h];
  int currentCell, topLeft, top, topRight, bottomLeft, bottom, bottomRight, left, right;

  for_position {
    currentCell = universe[line][column];
    top         = universe[line - 1][column];
    bottom      = universe[line + 1][column];
    left        = universe[line][column - 1];
    right       = universe[line][column + 1];
    topLeft     = universe[line - 1][column - 1];
    topRight    = universe[line - 1][column + 1];
    bottomLeft  = universe[line + 1][column - 1];
    bottomRight = universe[line + 1][column + 1];

    new[line][column] = nature(currentCell, topLeft, top, topRight, bottomLeft, bottom, bottomRight, left, right);
  }

  for_line for_column universe[line][column] = new[line][column];
}

void game(int w, int h){
  unsigned universe[h][w];
  for_column_by_line universe[line][column] = rand() < RAND_MAX / 5 ? 1 : 0;
  while (1) {
    show(universe, w, h);
    evolve(universe, w, h);
    usleep(200000);
  }
}

int main(){
  game(40, 40);
}

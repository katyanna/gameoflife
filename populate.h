#include "defs.h"

void populate(unsigned width, unsigned height, unsigned u[width][height]){
  printf("\033[H");
  for_line {
    for_column printf(u[line][column] ? "#" : " ");
    printf("\n");
  }
}

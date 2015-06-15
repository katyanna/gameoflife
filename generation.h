#include "defs.h"

struct Cells{
  unsigned currentCell;
  unsigned top, topRight, topLeft;
  unsigned bottom, bottomRight, bottomLeft;
  unsigned left, right;
};

int cellStatus(struct Cells cell){
  int living = cell.top + cell.bottom + cell.left + cell.right + cell.topLeft + cell.topRight + cell.bottomRight + cell.bottomLeft;

  if (cell.currentCell){
    if (living <= 1 || living >= 4) return 0;
    if (living == 2 || living == 3) return 1;
  } else {
    return (living == 3) ? 1 : 0;
  }
}

void generation(unsigned width, unsigned height, unsigned u[width][height]){
  unsigned new[width][height];
  struct Cells cell;

  for_position {
    cell.currentCell = u[line][column];
    cell.top         = u[line - 1][column];
    cell.bottom      = u[line + 1][column];
    cell.left        = u[line][column - 1];
    cell.right       = u[line][column + 1];
    cell.topLeft     = u[line - 1][column - 1];
    cell.topRight    = u[line - 1][column + 1];
    cell.bottomLeft  = u[line + 1][column - 1];
    cell.bottomRight = u[line + 1][column + 1];

    new[line][column] = cellStatus(cell);
  }

  for_line for_column u[line][column] = new[line][column];
}

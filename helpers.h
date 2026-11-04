#ifndef HELPERS_H
#define HELPERS_H
#include "arr.h"
#include <stdlib.h>

void getUserName(char *name, size_t buf_size);
int getUserMove();
void printMoves(char *players[2], Arr moves, int init_matches);

#endif

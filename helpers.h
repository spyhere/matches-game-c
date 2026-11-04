#ifndef HELPERS_H
#define HELPERS_H
#include "arr.h"
#include <stdlib.h>

void get_user_name(char *name, size_t buf_size);
int get_user_move();
void print_moves(char *players[2], Arr moves, int init_matches);

#endif

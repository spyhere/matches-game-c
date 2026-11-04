#ifndef ARR_H
#define ARR_H
#include <stdlib.h>

typedef struct Arr {
  int *p;
  size_t len;
  size_t capacity;
} Arr;

struct Arr new_arr(int capacity);
struct Arr push_arr(struct Arr arr, int element);
void print_arr(struct Arr arr);

#endif

#include "arr.h"
#include <stdio.h>

struct Arr new_arr(int capacity) {
  struct Arr a = {};
  int *p       = malloc(sizeof(int) * capacity);
  if (p == NULL) {
    printf("Couldn't allocate array of size %d\n", capacity);
    return a;
  }
  a.p        = p;
  a.len      = 0;
  a.capacity = capacity;
  return a;
}

struct Arr push_arr(struct Arr arr, int element) {
  if (arr.len + 1 >= arr.capacity) {
    size_t new_capacity = arr.capacity * 2;
    int *new_p          = malloc(sizeof(int) * new_capacity);
    if (new_p == NULL) {
      printf("Couldn't allocate new array size %zu\n", new_capacity);
      return arr;
    }
    for (int i = 0; i < arr.len; ++i) {
      new_p[i] = arr.p[i];
    }
    free(arr.p);
    arr.p        = new_p;
    arr.capacity = new_capacity;
  }
  arr.p[arr.len] = element;
  arr.len += 1;
  return arr;
}

void print_arr(struct Arr arr) {
  for (int i = 0; i < arr.len; ++i) {
    printf("%d\n", arr.p[i]);
  }
}

#ifndef ARR_H
#define ARR_H
#include <stdlib.h>

typedef enum {
  ARR_INT,
  ARR_STR,
} ARR_TYPE;

typedef struct Arr {
  union {
    int *ip;
    char *cp;
  } p;
  size_t len;
  size_t capacity;
  ARR_TYPE type;
} Arr;

typedef union {
  int i;
  char *str;
} NEW_ARR_VALUE;

struct Arr new_arr(int capacity, ARR_TYPE type);
struct Arr push_arr(struct Arr arr, NEW_ARR_VALUE element);

#endif

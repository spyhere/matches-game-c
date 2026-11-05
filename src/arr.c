#include "arr.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Arr new_arr(int capacity, ARR_TYPE type) {
  struct Arr a = {};
  void *p;
  switch (type) {
  case ARR_INT:
    p      = malloc(sizeof(int) * capacity);
    a.p.ip = p;
    break;
  case ARR_STR:
    p      = malloc(sizeof(char) * capacity);
    a.p.cp = p;
    break;
  default:
    fprintf(stderr, "Unrecognised array type\n");
    return a;
  }
  if (p == NULL) {
    fprintf(stderr, "Couldn't allocate array of size %d\n", capacity);
    return a;
  }
  a.len      = 0;
  a.capacity = capacity;
  a.type     = type;
  return a;
}

struct Arr push_arr_int(struct Arr arr, int element) {
  if (arr.len + 1 >= arr.capacity) {
    size_t new_capacity = arr.capacity * 2;
    int *new_p          = malloc(sizeof(int) * new_capacity);
    if (new_p == NULL) {
      fprintf(stderr, "Couldn't allocate new array size %zu\n", new_capacity);
      return arr;
    }
    for (size_t i = 0; i < arr.len; ++i) {
      new_p[i] = arr.p.ip[i];
    }
    free(arr.p.ip);
    arr.p.ip     = new_p;
    arr.capacity = new_capacity;
  }
  arr.p.ip[arr.len] = element;
  arr.len += 1;
  return arr;
}

struct Arr push_arr_str(struct Arr arr, char *element) {
  int chunk_len = strlen(element);
  if (arr.len + chunk_len >= arr.capacity) {
    size_t new_capacity = arr.capacity * 2;
    char *new_p         = malloc(sizeof(char) * new_capacity);
    if (new_p == NULL) {
      fprintf(stderr, "Couldn't allocate new array size %zu\n", new_capacity);
      return arr;
    }
    for (size_t i = 0; i < arr.len; ++i) {
      new_p[i] = arr.p.cp[i];
    }
    free(arr.p.cp);
    arr.p.cp     = new_p;
    arr.capacity = new_capacity;
  }
  for (size_t i = 0; i < chunk_len; ++i) {
    arr.p.cp[i + arr.len] = element[i];
  }
  arr.len += chunk_len;
  return arr;
}

struct Arr push_arr(struct Arr arr, ARR_VALUE element) {
  switch (arr.type) {
  case ARR_INT:
    arr = push_arr_int(arr, element.i);
    break;
  case ARR_STR:
    arr = push_arr_str(arr, element.str);
    break;
  }
  return arr;
}

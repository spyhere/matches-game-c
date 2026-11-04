#include "helpers.h"
#include <stdio.h>
#include <string.h>

void getUserName(char *name, size_t buf_size) {
  if (!fgets(name, buf_size, stdin)) {
    printf("Error on name input");
  }
  // Remove new line character after user pressed Enter
  name[strlen(name) - 1] = '\0';
}

int getUserMove() {
  char input[4];
  if (!fgets(input, 4, stdin)) {
    return -1;
  }
  return atoi(input);
}

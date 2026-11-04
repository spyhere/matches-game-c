#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

const int PLAYERS_NAME_BYTES   = 32;
const int MATCHES_START_OFFSET = 11;
const int MATCHES_MAX          = 19; // there can be from 0 to 19 matches
const int MAX_PLAYERS          = 2;
char COMPUTER_NAME[9]          = "Computer\0";

typedef struct Arr {
  int *p;
  size_t len;
  size_t capacity;
} Arr;

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

struct Arr calculateFibNumbers(struct Arr arr, int target) {
  int a = 1;
  int b = 1;
  while (b <= target) {
    arr     = push_arr(arr, b);
    int tmp = b;
    b       = b + a;
    a       = tmp;
  }
  return arr;
}

void getUserName(char *name, size_t buf_size) {
  if (!fgets(name, buf_size, stdin)) {
    printf("Error on name input");
  }
}

int main(void) {
  char name[PLAYERS_NAME_BYTES];
  printf("Enter your name: ");
  getUserName(name, PLAYERS_NAME_BYTES);
  // Remove new line character after user pressed Enter
  name[strlen(name) - 1] = '\0';

  char *players[2];

  printf("Shuffle...\n");
  srand(time(NULL));
  int init_matches                    = (rand() % MATCHES_MAX + MATCHES_START_OFFSET);
  int player_idx                      = (rand() % 2);
  players[player_idx]                 = name;
  players[++player_idx % MAX_PLAYERS] = COMPUTER_NAME;
  sleep(1);
  printf("%d matches for this game. First move goes to %s\n", init_matches, players[0]);

  struct Arr fibs = new_arr(16);
  fibs            = calculateFibNumbers(fibs, init_matches);
  print_arr(fibs);

  return 0;
}

#include "arr.h"
#include "helpers.h"
#include <math.h>
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

int main(void) {
  char name[PLAYERS_NAME_BYTES];
  printf("Enter your name: ");
  getUserName(name, PLAYERS_NAME_BYTES);

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

  struct Arr moves = new_arr(16);

  player_idx    = 0;
  int matches   = init_matches;
  int prev_move = matches;
  while (1) {
    int can_take = fmin(prev_move * 2, fmin(matches, init_matches - 1));
    if (matches - can_take == 0) {
      moves = push_arr(moves, can_take);
      break;
    }
    printf("%s move\n", players[player_idx]);
    printf("Availabe %d matches (%d total). Your move: ", can_take, matches);
    int move = getUserMove();
    while (move <= 0 || move > can_take) {
      printf("Check your input, You can only take from %d to %d matches!\n You decided to take: ",
             1, can_take);
      move = getUserMove();
    }
    matches -= move;
    moves = push_arr(moves, move);
    if (matches == 0) {
      break;
    }
    prev_move  = move;
    player_idx = (player_idx + 1) % 2;
  }
  printf("Game over\n");
  printf("%s wins\n", players[player_idx]);
  return 0;
}

#include "arr.h"
#include "bot.h"
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

int main(void) {
  char name[PLAYERS_NAME_BYTES];
  printf("Enter your name: ");
  getUserName(name, PLAYERS_NAME_BYTES);

  char *players[2];

  printf("Shuffle...\n");
  srand(time(NULL));
  int init_matches                    = (rand() % MATCHES_MAX + MATCHES_START_OFFSET);
  size_t player_idx                   = (rand() % 2);
  players[player_idx]                 = name;
  players[++player_idx % MAX_PLAYERS] = COMPUTER_NAME;
  sleep(1);
  printf("%d matches for this game. First move goes to %s\n", init_matches, players[0]);

  Bot bot          = new_bot(init_matches);
  struct Arr moves = new_arr(16, ARR_INT);

  player_idx    = 0;
  int matches   = init_matches;
  int prev_move = matches;
  while (1) {
    int can_take = fmin(prev_move * 2, fmin(matches, init_matches - 1));
    if (matches - can_take == 0) {
      moves = push_arr(moves, (NEW_ARR_VALUE){.i = can_take});
      break;
    }
    int move;
    if (players[player_idx] == COMPUTER_NAME) {
      move = fmin(get_bot_move(bot, matches), can_take);
      printf("Availabe %d matches (%d total). ...Computer takes %d\n", can_take, matches, move);
      sleep(1);
    } else {
      printf("Availabe %d matches (%d total). Your move: ", can_take, matches);
      move = getUserMove();
      while (move <= 0 || move > can_take) {
        printf("Check your input, You can only take from %d to %d matches!\nYou decided to take: ",
               1, can_take);
        move = getUserMove();
      }
    }
    matches -= move;
    moves = push_arr(moves, (NEW_ARR_VALUE){.i = move});
    if (matches == 0) {
      break;
    }
    prev_move  = move;
    player_idx = (player_idx + 1) % 2;
  }

  printf("\nGame over\n");
  printf("%s wins\n", players[player_idx]);
  printf("Initial amount of matches: %d\n", init_matches);
  printMoves(players, moves, init_matches);
  return 0;
}

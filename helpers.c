#include "helpers.h"
#include "arr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_user_name(char *name, size_t buf_size) {
  if (!fgets(name, buf_size, stdin)) {
    printf("Error on name input");
  }
  // Remove new line character after user pressed Enter
  name[strlen(name) - 1] = '\0';
}

int get_user_move() {
  char input[4];
  if (!fgets(input, 4, stdin)) {
    return -1;
  }
  return atoi(input);
}

void print_moves(char **players, Arr moves, int init_matches) {
  struct Arr str_buf = new_arr(128, ARR_STR);
  int player_idx     = 0;
  int remains        = init_matches;
  for (size_t i = 0; i < moves.len; ++i) {
    int cur_move = moves.p.ip[i];
    remains -= cur_move;
    char cur_str[48];
    sprintf(cur_str, "%s %d(%d)", players[player_idx], cur_move, remains);
    str_buf = push_arr(str_buf, (NEW_ARR_VALUE){.str = cur_str});
    if (player_idx == 0 && i != moves.len - 1) {
      str_buf = push_arr(str_buf, (NEW_ARR_VALUE){.str = " - "});
    } else {
      str_buf = push_arr(str_buf, (NEW_ARR_VALUE){.str = "\n"});
    }
    player_idx = (player_idx + 1) % 2;
  }
  printf("Moves:\n%s\n", str_buf.p.cp);
}

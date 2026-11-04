#ifndef BOT_H
#define BOT_H
#include "arr.h"

typedef struct {
  Arr fibs;
} Bot;

Bot new_bot(int target);
int get_bot_move(Bot bot, int target);

#endif

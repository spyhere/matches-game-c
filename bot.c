#include "bot.h"
#include "arr.h"
#include <stdio.h>
#include <stdlib.h>

struct Arr calculateFibNumbers(struct Arr arr, int target) {
  int a = 1;
  int b = 1;
  while (b <= target) {
    arr     = push_arr(arr, (NEW_ARR_VALUE){.i = b});
    int tmp = b;
    b       = b + a;
    a       = tmp;
  }
  return arr;
}

Bot new_bot(int target) {
  Bot bot;
  bot.fibs = new_arr(16, ARR_INT);
  bot.fibs = calculateFibNumbers(bot.fibs, target);
  return bot;
}

int get_bot_move(Bot bot, int target) {
  int res = target;
  for (size_t i = bot.fibs.len - 1; i > 0; --i) {
    if (target == bot.fibs.p.ip[i]) {
      return 1;
    }
    if (target > bot.fibs.p.ip[i]) {
      res %= bot.fibs.p.ip[i];
      break;
    }
  }
  size_t idx = bot.fibs.len - 1;
  while (res != bot.fibs.p.ip[idx] && idx >= 0) {
    if (res > bot.fibs.p.ip[idx]) {
      res %= bot.fibs.p.ip[idx];
    }
    --idx;
  }
  return res;
}

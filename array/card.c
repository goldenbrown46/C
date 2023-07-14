#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Card {
  char rank;
  char suit;
};

int check(struct Card * hand)
{
  const struct Card *p;
  for(p = hand; p->rank != 0; p++) {
    if (p->suit == 's' && p->rank == 'Q') {
      return 1;
    }
  }
  return 0;
}

int main()
{
  struct Card hand [] = {{'Q', 's'}, {'A','h'}, {'9', 'd'}, {0, 0}};
  struct Card * p;
  for (p=hand; p->rank != 0; p++) {
    printf("%c%c", p->rank, p->suit);
  }
  printf("\n");
  printf("%d\n", check(hand));

  return 0;
}
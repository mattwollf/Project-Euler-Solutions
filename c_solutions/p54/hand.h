#ifndef HAND_H
#define HAND_H

#include <stdint.h>

typedef enum {CLUB=1,SPADE=2,HEART=4,DIAMOND=8} suit;

typedef enum {HIGH_CARD,
              PAIR,
              TWO_PAIR,
              THREE_KIND,
              STRAIGHT,
              FLUSH,
              FULL_HOUSE,
              FOUR_KIND,
              STRAIGHT_FLUSH,
              ROYAL_FLUSH}
        hand_type;

typedef struct card{

        suit s;
        uint8_t v;

} card;

typedef struct hand{

        card c[5];
        hand_type t;

} hand;

hand *strToHand(const char str[static 15]);

int hasFourKindManual(hand *h);
int hasFourKindMemcpy(hand *h);
int hasFlush         (hand *h);
int hasStraight      (hand *h);
int hasStraightFlush (hand *h);
int hasRoyalFlush    (hand *h);
void sortHand        (hand *h);

int cmp_cards(const void *a, const void *b);

#endif

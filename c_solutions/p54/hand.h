#ifndef HAND_H
#define HAND_H

#include <stdint.h>

typedef enum {CLUB=1,SPADE=2,HEART=4,DIAMOND=8} suit;

typedef enum {HIGH_CARD=0,
              PAIR=1,
              TWO_PAIR=2,
              THREE_KIND=3,
              STRAIGHT=4,
              FLUSH=5,
              FULL_HOUSE=6,
              FOUR_KIND=7,
              STRAIGHT_FLUSH=8,
              ROYAL_FLUSH=9}
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

int hasPair          (hand *h);
int hasTwoPair       (hand *h);
int hasThreeKind     (hand *h);
int hasFourKindManual(hand *h);
int hasFourKindMemcpy(hand *h);
int hasFlush         (hand *h);
int hasFullHouse     (hand *h);
int hasStraight      (hand *h);
int hasStraightFlush (hand *h);
int hasRoyalFlush    (hand *h);
void sortHand        (hand *h);

int cntsets(const hand *h, int setsize);

size_t strchrcnt      (const char *str, char c);
size_t strchrcntManual(const char *str, char c);

int cmp_cards(const void *a, const void *b);

#endif

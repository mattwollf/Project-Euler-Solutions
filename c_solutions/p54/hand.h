#ifndef HAND_H
#define HAND_H

#include <stdint.h>

typedef enum {ERROR=-1,
              CLUB='C',
              SPADE='S',
              HEART='H',
              DIAMOND='D'
} suit;

typedef enum {NOT_FOUND=-1,
              HIGH_CARD=0,
              PAIR=1,
              TWO_PAIR=2,
              THREE_KIND=3,
              STRAIGHT=4,
              FLUSH=5,
              FULL_HOUSE=6,
              FOUR_KIND=7,
              STRAIGHT_FLUSH=8,
              ROYAL_FLUSH=9
} hand_type;

typedef struct card{

        suit s;
        uint_fast8_t v;
} card;

typedef struct hand{

        card *c;
        hand_type t;
        uint_fast8_t type_card;
} hand;

hand *strToHand(const char str[static 15]);
char * handToStr(const hand *h);

uint_fast8_t pairCardValue(const hand *h);
uint_fast8_t twoPairCardValue(const hand *h);
uint_fast8_t threeKindCardValue(const hand *h);
uint_fast8_t straightCardValue(const hand *h);
uint_fast8_t flushCardValue(const hand *h);
uint_fast8_t fourKindCardValue(const hand *h);

int hasPair          (const hand *h);
int hasTwoPair       (const hand *h);
int hasThreeKind     (const hand *h);
int hasStraight      (const hand *h);
int hasFlush         (const hand *h);
int hasFullHouse     (const hand *h);
int hasFourKind      (const hand *h);
int hasFourKindManual(const hand *h);
int hasFourKindMemcpy(const hand *h);
int hasStraightFlush (const hand *h);
int hasRoyalFlush    (const hand *h);

void sortHand        (hand *h);
void setHandType     (hand *h);
void setHandTypeCard (hand *h);

int cntsets(const hand *h, int setsize);

uint8_t *get_val_array(const hand *h);

size_t strchrcnt      (const char *str, char c);
size_t strchrcntManual(const char *str, char c);

int cmp_cards(const void *a, const void *b);
int cmp_hands(const void *a, const void *b);

#endif

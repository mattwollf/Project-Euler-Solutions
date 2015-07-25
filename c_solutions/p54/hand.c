#include <stdlib.h>
#include <string.h>

int hasFourKindManual(hand h)
{
        uint8_t first = (h.c)[0].v;
        uint8_t last  = (h.c)[4].v;

        for(int i = 1; i < 4; i++)
                first &= (h.c)[i].v;

        for(int i = 1; i < 5; i++)
                last &= (h.c)[i].v;

        return (h.c)[0].v == first || (h.c)[4].v == last;
}

int hasFourKindMemcpy(hand h)
{
        char vals[5];

        char testFirst[4];
        char  testLast[4];

        for(int i = 0; i < 5; i++)
                vals[i] = (h.c)[i].v;

        memset(testFirst, vals[0], 4);
        memset(testLast, vals[4], 4);

        return 0 == memcmp(testFirst,  vals,   sizeof(char) * 4) ||
               0 == memcmp( testLast,  vals+1, sizeof(char) * 4) ;
}

int hasFlush(hand h)
{
        const suit initial = (h.c)[0].s;

        suit test = initial;

        for(int i = 1; i < 5; i++)
                test = test | (h.c)[i].s;

        return initial == test;
}

int hasStraight(hand h)
{
        card *cards = h.c;

        uint8_t init = cards[0].v;

        return ++init == cards[1].v &&
               ++init == cards[2].v &&
               ++init == cards[3].v &&
               ++init == cards[4].v;
}

int hasStraightFlush(hand h)
{
        return hasStraight(h) && hasFlush(h);
}

int hasRoyalFlush(hand h)
{
        card *cards = h.c;

        return hasFlush(h)      &&
               cards[0].v == 1  &&
               cards[1].v == 10 &&
               cards[2].v == 11 &&
               cards[3].v == 12 &&
               cards[4].v == 13;
}

int cmp_cards(const void *a, const void *b)
{
        return ((card*)a)->v - ((card*)a)->v;
}

void sortHand(hand *h)
{
        qsort(h->c, 5, sizeof(card), cmp_cards);
}

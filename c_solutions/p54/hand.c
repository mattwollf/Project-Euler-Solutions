#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include <hand.h>

hand *strToHand(const char str[static 15])
{
        hand *h = malloc(sizeof(hand));

        card cards[5];

        for(int i = 0; i < 15; i += 3)
        {
                int c_i = i/3;
                if(isdigit(str[i]))
                        cards[c_i].v = str[i] - 48;
                else if(str[i] == 'A')
                        cards[c_i].v = 1;
                else if(str[i] == 'T')
                        cards[c_i].v = 10;
                else if(str[i] == 'J')
                        cards[c_i].v = 11;
                else if(str[i] == 'Q')
                        cards[c_i].v = 12;
                else if(str[i] == 'K')
                        cards[c_i].v = 13;
                else printf("ERROR received %c\n", str[i]);

                switch(str[i+1])
                {
                case 'C':
                        cards[c_i].s = CLUB;
                        break;
                case 'S':
                        cards[c_i].s = SPADE;
                        break;
                case 'H':
                        cards[c_i].s = HEART;
                        break;
                case 'D':
                        cards[c_i].s = DIAMOND;
                        break;
                default:
                        printf("ERROR received bad suit %c\n",str[i+1]);
                }
        }

        memcpy(h->c, cards, sizeof(card) * 5);

        sortHand(h);

        return h;
}
int hasFourKindManual(hand *h)
{
        uint8_t first = (h->c)[0].v;
        uint8_t last  = (h->c)[4].v;

        for(int i = 1; i < 4; i++)
                first &= (h->c)[i].v;

        for(int i = 1; i < 5; i++)
                last &= (h->c)[i].v;

        return (h->c)[0].v == first || (h->c)[4].v == last;
}

int hasFourKindMemcpy(hand *h)
{
        uint8_t vals[5];

        char testFirst[4];
        char  testLast[4];

        for(int i = 0; i < 5; i++)
                vals[i] = (h->c)[i].v;

        memset(testFirst, vals[0], 4);
        memset(testLast, vals[4], 4);

        return 0 == memcmp(testFirst,  vals,   sizeof(char) * 4) ||
               0 == memcmp( testLast,  vals+1, sizeof(char) * 4) ;
}

int hasFlush(hand *h)
{
        const suit initial = (h->c)[0].s;

        suit test = initial;

        for(int i = 1; i < 5; i++)
                test = test | (h->c)[i].s;

        return initial == test;
}

int hasStraight(hand *h)
{
        card *cards = h->c;

        uint8_t init = cards[0].v;

        return ++init == cards[1].v &&
               ++init == cards[2].v &&
               ++init == cards[3].v &&
               ++init == cards[4].v;
}

int hasStraightFlush(hand *h)
{
        return hasStraight(h) && hasFlush(h);
}

int hasRoyalFlush(hand *h)
{
        card *cards = h->c;

        return hasFlush(h)      &&
               cards[0].v == 1  &&
               cards[1].v == 10 &&
               cards[2].v == 11 &&
               cards[3].v == 12 &&
               cards[4].v == 13;
}

int cmp_cards(const void *a, const void *b)
{
        return ((const card*)a)->v - ((const card*)b)->v;
}

void sortHand(hand *h)
{
        qsort(h->c, 5, sizeof(card), cmp_cards);
}

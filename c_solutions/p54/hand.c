#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

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

void setHandType(hand *h)
{
        assert(h != NULL);

        if(hasRoyalFlush(h))
        {
                h->t = ROYAL_FLUSH;
        }

        else if(hasStraightFlush(h))
        {
                h->t = STRAIGHT_FLUSH;
        }
        else if(hasFourKind(h))
        {
                h->t = FOUR_KIND;
        }
        else if(hasFullHouse(h))
        {
                h->t = FULL_HOUSE;
        }
        else if(hasFlush(h))
        {
                h->t = FLUSH;
        }
        else if(hasStraight(h))
        {
                h->t = STRAIGHT;
        }
        else if(hasThreeKind(h))
        {
                h->t = THREE_KIND;
        }
        else if(hasTwoPair(h))
        {
                h->t = TWO_PAIR;
        }
        else if(hasPair(h))
        {
                h->t = PAIR;
        }
        else
        {
                h->t = HIGH_CARD;
        }
}

int hasFourKind(const hand *h)
{
        return hasFourKindManual(h);
}

int hasFourKindManual(const hand *h)
{
        return cntsets(h,4) > 0;
}

int hasFourKindMemcpy(const hand *h)
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

int hasTwoPair(const hand *h)
{
        return cntsets(h, 2) == 2 && cntsets(h,3) == 0;
}

int hasFlush(const hand *h)
{
        const suit initial = (h->c)[0].s;

        suit test = initial;

        for(int i = 1; i < 5; i++)
                test = test & (h->c)[i].s;

        return initial == test;
}

int hasStraight(const hand *h)
{
        const card *cards = h->c;

        uint8_t init = cards[0].v;

        return ++init == cards[1].v &&
               ++init == cards[2].v &&
               ++init == cards[3].v &&
               ++init == cards[4].v;
}

int hasStraightFlush(const hand *h)
{
        return hasStraight(h) && hasFlush(h);
}

int hasRoyalFlush(const hand *h)
{
        const card *cards = h->c;

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

size_t strchrcnt(const char *str, char c)
{
        unsigned int count = 0;

        char *last_c = strchr(str,c);

        while(last_c != NULL)
        {
                count++;
                last_c = strchr(last_c, c);
        }

        return count;
}

size_t strchrcntManual(const char *str, char c)
{
        const size_t   len = strlen(str);
              size_t count = 0;

        for(size_t i = 0; i < len; i++)
                if(str[i] == c)
                        count++;

        return count;
}

int hasFullHouse(const hand *h)
{
        return cntsets(h, 2) == 3 &&
               cntsets(h, 3) == 1 ;
}

int hasThreeKind(const hand *h)
{
        return cntsets(h,3) == 1 && cntsets(h,2) == 2;
}

int hasPair(const hand *h)
{
        return cntsets(h,2) == 1;
}

int cntsets(const hand *h, int setsize)
{
        int found = 0;
        const int lim = 5 - setsize + 1;

        uint8_t vals[5];

        for(int i = 0; i < 5; i++)
                vals[i] = (h->c)[i].v;

        for(int i = 0; i < lim; i++)
        {
                int cur_size = 1;

                for(int k = i+1; k-i < setsize; k++)
                {
                        if(vals[i] == vals[k])
                                cur_size++;
                }
                if(cur_size == setsize)
                        found++;
        }
        return found;
}

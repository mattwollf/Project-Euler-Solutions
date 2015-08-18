#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#include <hand.h>

uint_fast8_t pairCardValue(const hand * h)
{
        card *cards = h->c;

        for(int i = 0; i < 4; i++)
        {
                if(cards[i].v == cards[i+1].v)
                        return cards[i].v;
        }

        printf("ERROR no pair found in hand assumed to have pair\n");
        return 0;
}

uint_fast8_t twoPairCardValue(const hand *restrict h)
{
        return (h->c)[3].v;
}

uint_fast8_t threeKindCardValue(const hand *restrict h)
{
        return (h->c)[2].v;
}

uint_fast8_t straightCardValue(const hand *restrict h)
{
        return(h->c)[4].v;
}

uint_fast8_t flushCardValue(const hand *restrict h)
{
        return(h->c)[4].v;
}

uint_fast8_t fourKindCardValue(const hand *restrict h)
{
        return (h->c)[3].v;
}

void setHandTypeCard(hand *restrict h)
{
        switch(h->t)
        {
                case HIGH_CARD:
                        h->type_card = (h->c)[4].v;
                        break;
                case PAIR:
                        h->type_card = pairCardValue(h);
                        break;
                case TWO_PAIR:
                        h->type_card = twoPairCardValue(h);
                        break;
                case THREE_KIND:
                        h->type_card = threeKindCardValue(h);
                        break;
                case STRAIGHT:
                        h->type_card = straightCardValue(h);
                        break;
                case FLUSH:
                        h->type_card = flushCardValue(h);
                        break;
                case FULL_HOUSE:
                        h->type_card = threeKindCardValue(h);
                        break;
                case FOUR_KIND:
                        h->type_card = fourKindCardValue(h);
                        break;
                case STRAIGHT_FLUSH:
                        h->type_card = straightCardValue(h);
                        break;
                case ROYAL_FLUSH:
                        h->type_card = straightCardValue(h);
                        break;
                case NOT_FOUND:
                default:
                printf("ERROR bad hand type %d\n", h->t);
        }
}

uint_fast8_t charToValue(char c)
{
        if(isdigit(c))
                return (uint_fast8_t)(c - '0');
        else if(c == 'A')
                return 14;
        else if(c == 'T')
                return 10;
        else if(c == 'J')
                return 11;
        else if(c == 'Q')
                return 12;
        else if(c == 'K')
                return 13;

        printf("ERROR received %c\n", c);
        return 0;
}

char valueToChar(uint_fast8_t v)
{
        if(v < 10)
                return (char)(v + '0');
        else if(v == 10)
                return 'T';
        else if(v == 11)
                return 'J';
        else if(v == 12)
                return 'Q';
        else if(v == 13)
                return 'K';
        else if(v == 14)
                return 'A';

        printf("ERROR received %hhu\n", v);
        return -1;
}

suit charToSuit(char c)
{
        switch(c)
        {
                case 'C':
                case 'S':
                case 'H':
                case 'D':
                        return c;
                default:
                        printf("ERROR received bad suit %c\n",c);
                        return -1;
        }
}

char suitToChar(suit s)
{
        switch(s)
        {
                case SPADE:
                case CLUB:
                case DIAMOND:
                case HEART:
                case ERROR:
                        return (char)s;
                default:
                        return -1;
        }
}

hand *strToHand(const char str[static 15])
{
        hand *h = malloc(sizeof(hand));

        card *cards = malloc(sizeof(card) * 5);

        for(int i = 0; i < 15; i += 3)
        {
                int c_i = i/3;

                cards[c_i].v = charToValue(str[i  ]);
                cards[c_i].s = charToSuit( str[i+1]);
       }

        h->c = cards;

        sortHand(h);

        h->t = NOT_FOUND;
        setHandType(h);
        setHandTypeCard(h);

        return h;
}

char * handToStr(const hand *h)
{
        char *str = malloc(sizeof(char) * 31);

        //set every value in string to space
        memset(str, 32,29);

        str[30] = '\n';

        for(int i = 0; i < 5; i++)
        {
                card c = (h->c)[i];
                const int str_i = i * 3;

                str[str_i  ] = valueToChar(c.v);
                str[str_i+1] =  suitToChar(c.s);
        }

        return str;
}
uint_fast8_t *get_val_array(const hand *h)
{
        uint_fast8_t *vals = malloc(sizeof(uint_fast8_t) * 5);

        for(int i = 0; i != 5; i++)
        {
                vals[i] = (h->c)[i].v;
        }

        return vals;
}

int cmp_hands(const void *a, const void *b)
{
        const hand *ha = (const hand*)a;
        const hand *hb = (const hand*)b;

        const hand_type t_a = ((const hand *)a)->t;
        const hand_type t_b = ((const hand *)b)->t;

        const uint_fast8_t tca = ((const hand *)a)->type_card;
        const uint_fast8_t tcb = ((const hand *)b)->type_card;

        if(t_a == t_b)
        {
                if(tca == tcb)
                        return (ha->c)[4].v - (hb->c)[4].v;
                return tca - tcb;
        }

        return t_a - t_b;
}

void setHandType(hand *h)
{
        assert(h != NULL);

        if(h->t != NOT_FOUND)
                return;

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
        uint_fast8_t vals[5];

        char testFirst[4];
        char  testLast[4];

        for(int i = 0; i < 5; i++)
                vals[i] = (h->c)[i].v;

        memset(testFirst, vals[0], 4);
        memset(testLast , vals[4], 4);

        return  0 == memcmp(testFirst,  vals,   sizeof(char) * 4) ||
                0 == memcmp( testLast,  vals+1, sizeof(char) * 4) ;
}

int hasTwoPair(const hand *h)
{
        return cntsets(h, 2) == 2 && cntsets(h,3) == 0;
}

int hasFlush(const hand *h)
{
        const suit initial = (h->c)[0].s;

        for(int i = 1; i < 5; i++)
                if(initial != (h->c)[i].s)
                        return 0;

        return 1;
}

int hasStraight(const hand *h)
{
        const card *cards = h->c;

        uint_fast8_t init = cards[0].v;

        uint_fast8_t *vals = get_val_array(h);

        uint_fast8_t edge_case_straight[5];


        edge_case_straight[0] = 2;
        edge_case_straight[1] = 3;
        edge_case_straight[2] = 4;
        edge_case_straight[3] = 5;
        edge_case_straight[4] = 14;

        int rc = memcmp(edge_case_straight,
                        vals, sizeof(uint_fast8_t) * 5);

        free(vals);

        if(rc == 0)
               return 1;

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
        return  cntsets(h, 2) == 3 &&
                cntsets(h, 3) == 1  ;
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

        uint_fast8_t vals[5];

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

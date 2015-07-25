#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>

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
        int high_card;

} hand;

int cmp_cards(const void *a, const void *b)
{
        card ca = *(card*)a;
        card cb = *(card*)b;

        return ca.v - cb.v;
}

void sortHand(hand *h)
{
        qsort(h->c, 5, sizeof(card), cmp_cards);
}

int hasFourKind(hand h)
{
        char vals[5];

        const char *testFirst ;
        char testLast[4];

        for(int i = 0; i < 5; i++)
                vals[i] = (h.c)[i];


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

hand strToHand(char str[static 15])
{
        hand h;

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

        memcpy(h.c, cards, sizeof(card) * 5);

        sortHand(&h);

        return h;
}

int main(int argc, char *argv[])
{
        char *name = "poker.txt";

        FILE *file = NULL;

        file = fopen(name, "r");

        hand p1,p2;

        assert(file != NULL);

        char buffer[30];

        fgets(buffer, 30, file);

        printf("%s\n", buffer);

        p1 = strToHand(buffer);
        p2 = strToHand(buffer + 15);

        hand flushTest = strToHand("5H 4H 7H 8H TH");

        printf("%d\n", hasFlush(flushTest));

        fclose(file);
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>

#include <hand.h>

int cmp_cards(const void *a, const void *b)
{
        return ((card*)a)->v - ((card*)a)->v;
}

void sortHand(hand *h)
{
        qsort(h->c, 5, sizeof(card), cmp_cards);
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

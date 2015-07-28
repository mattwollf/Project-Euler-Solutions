#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>

#include <hand.h>

int main()
{
        const char *name = "poker.txt";

        FILE *file = NULL;

        file = fopen(name, "r");

        hand *p1,*p2;

        assert(file != NULL);

        char buffer[31];

        int p1wins = 0;
        int handNumber = 0;
        while( fgets(buffer, 31, file)!= NULL)
        {
                p1 = strToHand(buffer);
                p2 = strToHand(buffer + 15);

                int cmp_result = cmp_hands(p1,p2);

                handNumber++;
                if(p1->t == FLUSH ||
                   p2->t ==  FLUSH)
                {
                        char *p1Str = handToStr(p1);
                        char *p2Str = handToStr(p2);

                        printf("hand number: %d. winner:%d\n", handNumber, cmp_result);
                        printf("player 1: %s\n", p1Str);
                        printf("player 2: %s\n", p2Str);

                        free(p1Str);
                        free(p2Str);
                }
                if(cmp_result > 0)
                        p1wins++;

                free(p1);
                free(p2);
        }

        fclose(file);

        printf("p1wins: %d\n", p1wins);
        return 0;
}

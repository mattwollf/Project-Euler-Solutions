#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>

#include <hand.h>

int main()
{
        char *name = "poker.txt";

        FILE *file = NULL;

        file = fopen(name, "r");

        hand *p1,*p2;

        assert(file != NULL);

        char buffer[30];

        fgets(buffer, 30, file);

        printf("%s\n", buffer);

        p1 = strToHand(buffer);
        p2 = strToHand(buffer + 15);

        fclose(file);

        return 0;
}

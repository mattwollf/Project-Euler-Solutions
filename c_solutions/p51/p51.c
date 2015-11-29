#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "p51.h"

char *sieve;
size_t sieve_size;

int ilen(int n)
{
    return floor(log10(abs(n))) + 1;
}

char *itoa(int n)
{
    char *str = NULL;
    char *new_str = NULL;

    str = malloc(sizeof(char) * 15);

    int rc = sprintf(str, "%d", n);

    new_str = realloc(str, rc);

    if(new_str != NULL)
    {
        if(str != new_str)
        free(str);

        return new_str;
    }

    return str;
}

int main(int argc, char *argv[])
{
    int curr_n;

    sieve_size = 1000000;

    sieve = malloc(sizeof(char) * sieve_size);

    char buf[50];

    strcpy(buf, "56003");
    reverse(buf);
    size_t *indices = strndc(buf, '0');

    printf("%s\n",buf);

    fill_prime_sieve(sieve, sieve_size);

    size_t cnt = strcnt(buf, '0');

    printf("%d should be 2\n", cnt);

    for(int i = 0; i < cnt; i++)
    {
        printf("0 found at %d\n", indices[i]);
    }

    free(sieve);

    size_t** pset = malloc(sizeof(size_t *) * 8);

    for(int i = 0; i != 8; i++)
    {
        pset[i] = malloc(sizeof(size_t) * 5);
        memset(pset[i], -1, sizeof(size_t) * 5);
    }

    size_t test[3] = {1, 2, 3};

    size_t setLength = powerset_wrapper(test, 3, pset);

    int i = 0;
    while(i < setLength)
    {
        int j = 0;
        putchar('[');
        while(pset[i][j] != -1)
        {
            printf(" %lu", pset[i][j]);
            ++j;
        }
        fputs(" ]\n", stdout);
        ++i;
    }

    return 0;
}

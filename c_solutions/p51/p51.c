#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "sieve.h"

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

int find_primes(int n, int a, int b)
{
        char *n_str = itoa(n);

        int n_family = 0;

        int smallest_prime = INT_MAX;

        for(int i = 0; i != 10; i++)
        {
                n_str[a] = n_str[b] = i + '0';

                int test = atoi(n_str);

                if(sieve[test])
                {
                        n_family++;

                        if(smallest_prime > test)
                                smallest_prime = test;
                }
        }

        free(n_str);

        if(n_family == 7)
                return smallest_prime;

        return -1;
}

int find_family(int n)
{
        const int len = ilen(n);

        int rc;

        for(int i = 0; i < len; i++)
        {
                for(int j = 0; i != len; i++)
                {
                        if(j == i) continue;

                        rc = find_primes(n, i, j);

                        if(rc != -1)
                                printf("%d\n", rc);
                }
        }

        return
}

int main(int argc, char *argv[])
{
        int curr_n;

        sieve_size = 1000000;

        sieve = malloc(sizeof(char) * sieve_size);

        fill_prime_sieve(sieve, sieve_size);

        find_family(56003);

        free(sieve);

        return 0;
}

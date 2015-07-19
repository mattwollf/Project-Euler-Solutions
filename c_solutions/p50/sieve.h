#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int fill_prime_sieve(char *sieve, size_t limit)
{
        size_t i, j;

        if(sieve == NULL)
                return 0;

        sieve[0] = sieve[1] = 0;

        memset(sieve, 1, limit);

        //for(i = 2; i < limit; i++) sieve[i] = 1;

        for(i = 2; i < limit; i++)
        {
                if(sieve[i] == 0) continue;

                for( j = i * i; j < limit; j+= i)
                {
                        sieve[j] = 0;
                }
        }
        return 0;
}

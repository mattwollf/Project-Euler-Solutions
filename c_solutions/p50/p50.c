#include "sieve.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
        char *sieve = NULL;

        const size_t limit = 1000000;

        sieve = malloc(sizeof(char) * limit);

        fill_prime_sieve(sieve, limit);

        size_t curr_max_sum = 900000;

        size_t sum = 0;

        for(int lower = 2; lower < limit; lower++)
        {
                if(sieve[lower] == 0) continue;

                int index = lower;

                sum = 0;

                do{
                        if(sieve[index] == 0)
                        {
                                index++;
                                continue;
                        }

                        sum += index++;

                } while (sum + index < 1000000);

                if(sieve[sum] && sum > curr_max_sum)
                {
                        printf("%d %d %d\n", sum, index, lower);

                        curr_max_sum = sum;
                }
        }

        return 0;
}

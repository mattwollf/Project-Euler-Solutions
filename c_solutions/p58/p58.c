#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "sieve.h"

typedef enum{RIGHT=0, UP=1, LEFT=2, DOWN=3} direction;

/*
int nearest_square_lessthan(int n)
{
        for(int i = 1; i * i < n; i++)
                if( ++i * i > n
}
*/
int is_spiral(size_t n)
{
        int i = 1;
        int stepsize = 2;
        int stepcounter = 0;
        do {

               i += stepsize;

               stepcounter = ++stepcounter % 4

               if(stepcounter == 0)
                       stepsize = stepsize << 1;

        } while(i < n);

        return i == n;

}

void fill_spiral(int** array, const size_t lim)
{
        int x = lim / 2;
        int y = x;


}

int main()
{
        int array[1001][1001];
        char sieve[1000000];

        fill_prime_sieve(sieve, 1000000);


        return 0;
}

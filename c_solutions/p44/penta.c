#include "penta.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <limits.h>
#include <assert.h>

#include <math.h>

#define PENTA_MAX 26755

#define PENTA_EQ(n) ((sqrt(24 * (n) + 1) + 1) / 6)
#define IS_PENTA(n) (floor(PENTA_EQ(n)) == ceil(PENTA_EQ(n)))

#define PENTA(n) ((3 * (n) * (n) - (n)) / 2)

int compare_int(void *a, void *b)
{
        return *(int *)a - *(int *)b;
}

double inverse_penta(int n)
{
        return (sqrt(24 * n + 1) + 1) / 6;
}

int is_penta(int n)
{
        const double rc = inverse_penta(n);

        return floor(rc) == ceil(rc);
}

int compare_pentas(int j, int k)
{
        return is_penta(k-j) &&
               is_penta(k+j)  ;
}

int main(int argc, char *argv[])
{
        int penta_diff = INT_MAX;

        for(int i = PENTA_MAX; i != 2; i--)
        {
                for(int j = i-1;j != 1; j--)
                {
                        const int temp_diff = PENTA(j) - PENTA(i);

                        if(compare_pentas(PENTA(j), PENTA(i)))
                        {
                                printf("FOUND %d %d\n", i, j);
                                if(temp_diff < penta_diff)
                                        penta_diff = temp_diff;
                        }
                }
        }

	return 0;
}

int penta(int n)
{
	return (3 * n * n - n) / 2;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>

long double fac(long double n)
{
        long double sum = n;
        while(n --> 1)
                sum *= n;

        return sum;
}

long double comb(long double n, long double r)
{
        return fac(n) / (fac(r) * fac(n - r));
}

int main(int argc, char**arg)
{

        int nums = 0;
        for(long double n = 1; n < 101; n++)
        {
                for(long double r = 1; r < n; r++)
                {
                        if(comb(n,r) > 1000000.0)
                        {
                                nums++;
                                printf("%llf\n",comb(n,r));
                        }
                }
        }

        printf("%d\n",nums);
        return 0;
}

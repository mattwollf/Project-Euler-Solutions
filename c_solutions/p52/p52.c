#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

int chcmp(const void *a, const void *b)
{
        return *(char *)a - *(char *)b;
}

int isPerm(int a, int b)
{
        if(a == b) return 1;

        char astr[15], bstr[15];

        memset(astr, 0, 15);
        memset(bstr, 0, 15);

        snprintf(astr, 14, "%d", a);
        snprintf(bstr, 14, "%d", b);

        qsort(astr, 15, sizeof(char), chcmp);
        qsort(bstr, 15, sizeof(char), chcmp);

        return 0 == memcmp(astr, bstr, 15);

}

int main(int argc, char *argv[])
{
        for(int i = 125874; i < INT_MAX/6; i++)
        {
                int x2,x3,x4,x5,x6;
                x2 = i * 2;
                x3 = i * 3;
                x4 = i * 4;
                x5 = i * 5;
                x6 = i * 6;

                int pred = isPerm(i, x6) &&
                           isPerm(i, x3) &&
                           isPerm(i, x4) &&
                           isPerm(i, x5) &&
                           isPerm(i, x2);

                if(pred)
                        printf("%d\n", i);
        }
        return 0;
}

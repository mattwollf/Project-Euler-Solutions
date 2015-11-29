#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct node{
    size_t data;
    struct node *next;
};

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

const size_t strcnt(const char *str, int character)
{
    size_t count = 0;

    while(*str != '\0')
    {
        if(*str == character)
        count++;

        ++str;
    }

    return count;
}

void reverse(char *str)
{
    size_t upper = strlen(str) - 1;
    size_t lower = 0;

    char c;
    while(lower < upper)
    {
        c = str[lower];
        str[lower++] = str[upper];
        str[upper--] = c;
    }
}

void powerset_array(size_t *v, size_t n, size_t *buf, size_t buf_n, size_t ***dst_p)
{
    size_t **dst = *dst_p;

    if(!n){
        int i = 1;
        size_t *workingSubset = dst[0];
        while(buf_n != 0){
            workingSubset[i] = *buf;
            --buf;
        }
    }
}

void powerset(size_t *v, size_t n, struct node *up, size_t ***dst_p)
{
    size_t **dst = *dst_p;
    struct node me;

    if(!n){ // if n > 0
        int i = 1;
        size_t * workingSubset = dst[0];
        while(up){
            workingSubset[i] = up->data;
            up = up->next;
            i++;
        }

        workingSubset[0] = i-1;
        (*dst_p)++;

    } else {
        me.data = *v;
        me.next = up;
        powerset(v+1, n-1,  up, dst_p);
        powerset(v+1, n-1, &me, dst_p);
    }
}

size_t powerset_wrapper(size_t *v, size_t n, size_t **dst)
{
    powerset(v, n, NULL, &dst);

    return 1 << n;
}

size_t* strndc(const char *str, int character)
{
    size_t count = 0;

    const size_t len = strlen(str);

    size_t * occurrences = malloc(sizeof(size_t) * len);
    size_t * o = occurrences;

    const char *c = str;

    while(*c != '\0')
    {
        if(*c == character){
            ++count;
            *o = c - str;
            ++o;
        }

        ++c;
    }

    return occurrences;
}

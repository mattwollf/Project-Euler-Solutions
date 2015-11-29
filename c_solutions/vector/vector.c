#include "vector.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define       ARRAY(x) ((x) ->       array)
#define         CAP(x) ((x) ->    capacity)
#define     MEMBERS(x) ((x) -> num_members)
#define MEMBER_SIZE(x) ((x) -> member_size)

struct mwVector {

        void *array;

        size_t capacity;
        size_t num_members;

        size_t member_size;
};


int mwv_init(mwVector **v, size_t member_size)
{
        if(v == NULL || *v != NULL)
                return -1;

        mwVector *new_vector = NULL;

        new_vector = malloc(sizeof(mwVector));

        if(new_vector == NULL)
                return -1;

        CAP(new_vector) = 4;

        MEMBERS(new_vector) = 0;

        MEMBER_SIZE(new_vector) = member_size;

        ARRAY(new_vector) = malloc(4 * member_size);

        if(ARRAY(new_vector) == NULL)
        {
                free(new_vector);
                return -1;
        }

        *v = new_vector;
        return 0;
}

int mwv_clear(mwVector *v)
{
        if(v == NULL)
                return -1;

        // if vector is already empty, then it is cleared
        if(MEMBERS(v) == 0)
                return 0;

        void * rc = realloc(ARRAY(v), MEMBER_SIZE(v) * 4);
}

int mwv_empty(mwVector *v)
{
        if(v == NULL)
                return -1;

        return MEMBERS(v) < 1;
}

int mwv_destroy(mwVector **v)
{
        if(v == NULL || *v == NULL)
                return -1;

        mwVector *mwv = *v;

        free(ARRAY(mwv));

        free((void *) mwv);

        return 0;
}

int mwv_resize(mwVector *v, size_t new_max_size)
{
        if(v == NULL)
                return -1;

        size_t const new_size = new_max_size * MEMBER_SIZE(v);
        void * const new_array = realloc(ARRAY(v), new_size);

        if(new_array == NULL)
                return -1;

        ARRAY(v) = new_array;

        CAP(v) = new_max_size;

        if(new_max_size < MEMBERS(v))
        {
                MEMBERS(v) = new_max_size;
        }

        return 0;
}

int mwv_push_back(mwVector *v, void *data)
{
        if(v == NULL || data == NULL)
                return -1;

        if(CAP(v) <= MEMBERS(v) + 1)
        {
                mwv_resize(v, CAP(v) << 1);
        }

        size_t const offset = MEMBERS(v) * MEMBER_SIZE(v);

        void * const dest = ARRAY(v) + offset;

        memcpy(dest, data, MEMBER_SIZE(v));

        MEMBERS(v)++;

        return 0;
}

int mwv_pop_back(mwVector *v, void **rdata)
{
        if(v == NULL || rdata == NULL || *rdata != NULL)
                return -1;

        if(MEMBERS(v) == 0)
                return -1;

        *rdata  = malloc(MEMBER_SIZE(v));

        if(*rdata == NULL)
                return -1;

        size_t const offset = MEMBER_SIZE(v) * (MEMBERS(v) - 1);

        void * const src = ((char *)ARRAY(v)) + offset;

        memcpy(*rdata, src, MEMBER_SIZE(v));

        MEMBERS(v)--;

        return 0;
}

int mwv_shrink_to_fit(mwVector *v)
{
        if(v == NULL)
                return -1;

        void * rc;
        size_t const shrunk_size = MEMBERS(v) + 1;

        if(CAP(v) > shrunk_size)
        {
                rc = realloc( ARRAY(v), shrunk_size + 1);

                if(rc == NULL)
                        return -1;

                ARRAY(v) = rc;

                CAP(v) = shrunk_size;
        }
        return 0;
}

int mwv_assign(mwVector *v,
               void *data,
               size_t incoming_size,
               size_t index)
{
        if(v == NULL || data == NULL || incoming_size == 0)
                return -1;

        if(MEMBER_SIZE(v) == 0)
                MEMBER_SIZE(v) = incoming_size;

        else if(incoming_size != MEMBER_SIZE(v))
        {
                return -1;
        }

        while(index >=  CAP(v))
                mwv_resize(v, CAP(v) * 2);

        size_t const offset = index * MEMBER_SIZE(v);

        void * const dest = ((char *)ARRAY(v)) + offset;

        memcpy(dest, data, MEMBER_SIZE(v));

        return 0;
}

int mwv_at(mwVector *v, size_t n, void **rdata)
{
        if(v == NULL || rdata == NULL || *rdata != NULL)
                return -1;

        if(MEMBERS(v) < n)
                return -1;

        *rdata = malloc(MEMBER_SIZE(v));

        if(*rdata == NULL)
                return -1;

        size_t const offset = n * MEMBER_SIZE(v);

        void * const source = ((char *)ARRAY(v)) + offset;

        memcpy(*rdata, source,  MEMBER_SIZE(v));

        return 0;
}

int mwv_front(mwVector *v, void **rdata)
{
        if(v == NULL || rdata == NULL || *rdata != NULL)
                return -1;

        if(MEMBERS(v) == 0)
                return -1;

        *rdata = malloc(MEMBER_SIZE(v));

        if(*rdata == NULL)
                return -1;

        memcpy(*rdata, ARRAY(v), MEMBER_SIZE(v));

        return 0;
}

int mwv_back(mwVector *v, void **rdata)
{
        if(v == NULL || rdata == NULL || *rdata != NULL)
                return -1;

        if(MEMBERS(v) == 0)
                return -1;

        *rdata = malloc(MEMBER_SIZE(v));

        if(*rdata == NULL)
                return -1;

        size_t const offset = (MEMBERS(v) - 1) * MEMBER_SIZE(v);

        void * const member_p = ((char *)ARRAY(v)) + offset;

        memcpy(*rdata, member_p, MEMBER_SIZE(v));

        return 0;
}



void *mwv_iterator(mwVector *v, void *curr)
{
        if(v == NULL || MEMBER_SIZE(v) == 0)
                return NULL;

        if(curr == NULL)
                return ARRAY(v);

        size_t const last = (MEMBERS(v) - 1) * MEMBER_SIZE(v);

        void * const array_limit = ARRAY(v) + last;

        if(curr >= array_limit)
                return array_limit;

        return ((char *)ARRAY(v)) + MEMBER_SIZE(v);
}

#undef ARRAY
#undef CAP
#undef MEMBERS
#undef MEMBER_SIZE

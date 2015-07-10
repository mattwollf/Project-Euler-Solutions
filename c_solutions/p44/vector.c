#include "vector.h"

#include <stdlib.h>
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
        if(!v || *v)
                return -1;

        mwVector *new_vector = NULL;

        new_vector = malloc(sizeof(mwVector));

        CAP(new_vector) = 4;

        MEMBERS(new_vector) = 0;

        MEMBER_SIZE(new_vector) = member_size;

        ARRAY(new_vector) = malloc(4 * member_size);

        if(!ARRAY(new_vector))
        {
                free(new_vector);
                return -1;
        }

        *v = new_vector;
        return 0;
}


#undef ARRAY
#undef CAP
#undef MEMBERS
#undef MEMBER_SIZE

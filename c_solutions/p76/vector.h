#ifndef MWVECTOR_H
#define MWVECTOR_H

#include <stddef.h>

typedef struct mwVector mwVector;

/**
 * initializes a vector
 *
 * @param v pointer to a NULL pointer to be initialized to an empty vector
 */
int mwv_init(mwVector **v, size_t member_size);

/**
 * frees the vector and all objects still inside it
 *
 * @param v a pointer to the vector to be destroyed
 * @return 0 if success, -1 if failure
 */
int mwv_destroy(mwVector **v);

int mwv_empty(mwVector *v);

int mwv_resize(mwVector *v, size_t new_size);

int mwv_shrink_to_fit(mwVector *v);

int mwv_at(mwVector *v, size_t n, void **rdata);

int mwv_assign(mwVector *v,
               void     *data,
               size_t   incoming_size,
               size_t   index);

int mwv_front(mwVector *v, void **rdata);
int mwv_back (mwVector *v, void **rdata);

int mwv_push_back(mwVector *v, void *data  );
int mwv_pop_back (mwVector *v, void **rdata);

#endif

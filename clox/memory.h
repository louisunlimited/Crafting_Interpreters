#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

/*
 * A macro to make it easier to define a function that calculates new capacity
 * We follow the same convention as the C standard library, doubling the capacity
 */
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

/*
 * A macro for create/grow a new array
 * The macro casts the returned void* back to the right type
 */
#define GROW_ARRAY(type, pointer, oldCount, count) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (count))

/*
 * A macro for freeing an array
 */
#define FREE_ARRAY(type, pointer, oldCount) reallocate(pointer, sizeof(type) * (oldCount), 0)

/*
 * Helper for GROW_ARRAY to free memory and reallocate
 *
 * @param pointer: the pointer to the memory to reallocate
 * @param oldSize: the old size of the memory
 * @param newSize: the new size of the memory
 * @return: A void* pointer to the new memory
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif

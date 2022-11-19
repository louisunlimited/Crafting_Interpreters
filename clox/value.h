#ifndef clox_value_h
#define clox_value_h

#include "common.h"

/* Support only double for now */
typedef double Value;

/* A constant pool */
typedef struct {
  int capacity;
  int count;
  Value* values;
} ValueArray;

/*
 * A `constructor` for initializing a value array
 *
 * @param array: The array to initialize
 * @return: void
 */ 
void initValueArray(ValueArray* array);

/*
 * A function to deallocate a value array
 *
 * @param array: The array to deallocate
 * @return: void
 */
void freeValueArray(ValueArray* array);

/*
 * A function to print a value
 * @param value: The value to print
 * @return: void
 */
void printValue(Value value);

/*
 * A function to write a value to a value array
 *
 * @param array: The array to write to
 * @param value: The value to write
 * @return: void
 */
void writeValueArray(ValueArray* array, Value value);
#endif

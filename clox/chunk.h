#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

/* This file contains the module to define our code representation */

// each instruction has a one-byte opcode, defined in the enum below
typedef enum {
    OP_RETURN,
} OpCode;

// a chunk is an dynamic array of instructions (opcodes)
// basically, we are creating a dynamic array ourselves here
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

/*
 * A `constructor` for initializing a chunk
 *
 * @param chunk: the chunk to initialize
 * @return: void
 */ 
void initChunk(Chunk* chunk);

/*
 * A function to deallocate a chunk
 *
 * @param chunk: the chunk to deallocate
 * @return: void
 */
void freeChunk(Chunk* chunk);

/*
 * A function to append a byte to a chunk
 * @param chunk: the chunk to append to
 * @param byte: the byte to append
 * @return: void
 */
void writeChunk(Chunk* chunk, uint8_t byte);
#endif

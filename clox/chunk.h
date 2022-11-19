#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

/* This file contains the module to define our code representation */

// each instruction has a one-byte opcode, defined in the enum below
typedef enum {
    OP_CONSTANT, // 00|23 - 00 is the opcode, 23 is the operand
    OP_RETURN, // 01 - no operand
} OpCode;

// a chunk is an dynamic array of instructions (opcodes)
// basically, we are creating a dynamic array ourselves here
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines; // line numbers for each instruction, tho inefficient, it won't take up spaces in CPU
    ValueArray constants;
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
 * #param line: the line number of the instruction
 * @return: void
 */
void writeChunk(Chunk* chunk, uint8_t byte, int line);

/*
 * A function to append a new constant to a chunk
 * @param chunk: the chunk to append to
 * @param value: the value to append
 * @return: int - the index of the constant in the chunk's constant pool
 */
int addConstant(Chunk* chunk, Value value);

#endif

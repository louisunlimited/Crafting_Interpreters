#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

/*
 * A function to disassemble a chunk.
 * A dissassembler is a program that translates machine code into assembly code.
 *
 * @param chunk: the chunk to disassemble
 * @param name: the name of the chunk
 * @return: void
 */
void disassembleChunk(Chunk* chunk, const char* name);

/*
 * A function to disassemble a single instruction.
 *
 * @param chunk: the chunk to disassemble
 * @param offset: the offset of the instruction to disassemble
 * @return: the offset of the next instruction
 */
int disassembleInstruction(Chunk* chunk, int offset);

/*
 * A helper for disassembleInstruction to print the instruction.
 * @param name: the name of the instruction
 * @param offset: the offset of the instruction
 * @return: the offset of the next instruction
 */
static int simpleInstruction(const char* name, int offset);

#endif

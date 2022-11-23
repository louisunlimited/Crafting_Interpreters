#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

typedef struct {
  Chunk* chunk;
  uint8_t* ip; // keeps track of where we are in the chunk (instruction pointer)
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretResult;

/*
 * Initializes the virtual machine.
 */
void initVM();

/*
 * Frees the virtual machine.
 */
void freeVM();

/*
 * Main entry point into the VM
 * Interprets the given chunk.
 */
InterpretResult interpret(Chunk* chunk);

#endif

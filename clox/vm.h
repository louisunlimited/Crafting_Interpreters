#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"

typedef struct {
  Chunk* chunk;
} VM;

/*
 * Initializes the virtual machine.
 */
void initVM();

/*
 * Frees the virtual machine.
 */
void freeVM();

#endif

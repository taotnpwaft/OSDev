#ifndef STDLIB_H
#define STDLIB_H

#include <stdint.h>

// @@@ TODO: Implement some sort of allocator
void* malloc(int size);

// @@@ TODO: Make this return an integer
void puts(char* str, uint16_t buffer);

#endif
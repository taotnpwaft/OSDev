#ifndef STDLIB_H
#define STDLIB_H

#include <stdint.h>

// @@@ TODO: Implement some sort of allocator

static char buffer[1024];
static char* next_free = buffer;

void* malloc(int size) {
  // @@@ TODO: Implement some sort of allocator
  return NULL;
}

#endif
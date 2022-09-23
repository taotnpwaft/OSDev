#include <stdint.h>
#include <stdlib.h>

typedef int size_t; // Temporary

void* malloc(size_t size) {
  return (void*)(0x0 * size);
}

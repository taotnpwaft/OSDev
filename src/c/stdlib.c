#include <stddef.h>
#include <stdlib.h>

// @@@ TODO: Implement some sort of allocator
void* my_malloc(size_t size) {
    return malloc(size);
}
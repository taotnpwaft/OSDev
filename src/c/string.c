#include <string.h>
#include <stdint.h>

int my_strlen(char* str) {
  int sum = 0;
  int i = 0;
  for (;;) {
    if (str[i] != '\0') {
      sum++;
      i++;
    } else {
      return ++sum;
    }
  }
}

void my_memset(void* dest, int ch, int count) {
  uint8_t* byte_dest = (uint8_t*)dest;
  for (int i = 0; i < count; i++)
    byte_dest[i] = (uint8_t)ch;
}

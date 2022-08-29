#include <string.h>
#include <stdint.h>

int strlen(char* str) {
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

void memset(void* dest, int ch, int count) {
  for (int i = 0; i < count; i++)
    *((uint8_t*)(dest + i)) = ch;
}

#include <string.h>
#include <stdint.h>

int strlen(char* str) {
  int sum = 0;
  uint8_t i = 0;
  for (;;) {
    if (str[i] != '\0') {
      sum++;
      i++;
    } else {
      return ++sum;
    }
  }
}

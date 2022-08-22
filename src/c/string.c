#include <string.h>
#include <stdint.h>

int strlen(char* str) {
  int sum = 0;
  char i = 0;
  for (;;) {
    if (str[i] != '\0') {
      sum++;
      i++;
    } else {
      return ++sum;
    }
  }
}

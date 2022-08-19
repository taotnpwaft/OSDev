#include <stdio.h>
#include <stdint.h>

#include "tty.h"

void kernel_main() {
  uint16_t* term = init_terminal();

  fg_color = WHITE;
  puts("Hello, World!", term);
}
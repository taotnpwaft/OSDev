#include <stdio.h>
#include <stdint.h>

#include "tty.h"

int fg_color = WHITE;
int bg_color = BLACK;

void kernel_main(uint16_t* term) {
  //extern uint32_t* _HEAP;

  puts("kernel_main()\n", term);
  puts("Hello, World!\n", term);
}
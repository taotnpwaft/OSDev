#include <stdint.h>
#include <stdio.h>

#include "tty.h"

void init_terminal(uint16_t* vga_buf) {
  for (int i = 0; i < TERM_WIDTH * TERM_HEIGHT; i++) {
    vga_buf[i] = 0;
  }
}

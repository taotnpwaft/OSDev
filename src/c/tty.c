#include <stdint.h>

#include "tty.h"

uint16_t* init_terminal() {
  uint16_t* vga_buf = (uint16_t*)0xB8000;

  for (int i = 0; i < TERM_WIDTH * TERM_HEIGHT; i++) {
    vga_buf[i] = 0;
  }

  return vga_buf;
}

#include <stdint.h>
#include "tty.h"

uint16_t* init_terminal() {
  uint16_t* vga_buf = (uint16_t*)0xB8000;

  uint16_t character = 97;
  // Too lazy to convert to hexadecimal
  uint16_t color = 0b0000111100000000;
  uint16_t a = character | color;

  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    vga_buf[i] = a;
  }

  return vga_buf;
}
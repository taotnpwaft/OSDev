#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "tty.h"

fg_color = BLACK;
bg_color = BLACK;

static int row = 0;
static int col = 0;

void puts(uint8_t* str, uint16_t* buffer) {
  for (int i = 0; i < strlen(str) - 1; i++) {
    putc(str[i], buffer);
  }
}

void putc(uint8_t c, uint16_t* buffer) {
  if (c == '\n') {
    row++;
    col = 0;
    return;
  }
  
  // Encode 16 bits for each character
  uint16_t output = c | fg_color << 8 | bg_color << 12;
  buffer[(TERM_WIDTH * row) + col] = output;
  col++;
}
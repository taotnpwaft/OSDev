#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "tty.h"

fg_color = BLACK;
bg_color = BLACK;

static int row = 0;
static int col = 0;

void puts(char* str, uint16_t* buffer) {
  for (int i = 0; i < strlen(str) - 1; i++) {
    putc(str[i], buffer);
  }
}

void putc(char c, uint16_t* buffer) {
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

// @@@ TODO: Implement print_num
void print_num(uint32_t num) {
  
}
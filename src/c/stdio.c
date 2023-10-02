#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include "stdio.h"

#include "tty.h"

extern int fg_color;
extern int bg_color;

extern void my_putc_char(char c, uint16_t* buffer);

static int row = 0;
static int col = 0;

void my_puts_str(const char* str, uint16_t* buffer);

void my_puts_str(const char* str, uint16_t* buffer) {
  for (int i = 0; i < strlen(str); i++) {
        my_putc_char(str[i], buffer);
  }
}

void my_putc_char(char c, uint16_t* buffer) {
  if (c == '\n') {
    row++;
    col = 0;
    return;
  }

  // Encode 16 bits for each character
  uint16_t output = c | (fg_color << 8) | (bg_color << 12);
  buffer[(TERM_WIDTH * row) + col] = output;
  col++;
}
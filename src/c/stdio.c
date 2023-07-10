#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>

#include "tty.h"

typedef unsigned long size_t;

extern size_t strlen(const char*);

static int row = 0;
static int col = 0;

// Global variables for foreground and background colors
int fg_color; // Replace with the desired default foreground color
int bg_color; // Replace with the desired default background color

void my_puts_str(const char* str, uint16_t* buffer) {
  for (size_t i = 0; i < strlen(str); i++) {
        my_puts_str(&str[i], buffer);
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
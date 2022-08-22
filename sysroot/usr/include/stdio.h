#ifndef STDIO_H
#define STDIO_H

#include <stdint.h>

extern int fg_color;
extern int bg_color;
extern int blink;

void puts(char* str, uint16_t* buffer);
void putc(char c, uint16_t* buffer);

// Non standard
// @@@ TODO: Overload for different integer types
void print_num(uint32_t n);

#endif
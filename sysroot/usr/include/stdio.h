#ifndef STDIO_H
#define STDIO_H

#include <stdint.h>

extern int fg_color;
extern int bg_color;
extern int blink;

void puts(uint8_t* str, uint16_t* buffer);
void putc(uint8_t c, uint16_t* buffer);

#endif
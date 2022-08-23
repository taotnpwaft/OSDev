#ifndef STDIO_H
#define STDIO_H

#include <stdint.h>

#include "tty.h"

extern int fg_color;
extern int bg_color;

void puts(char* str, uint16_t* buffer);
void putc(char c, uint16_t* buffer);

#endif
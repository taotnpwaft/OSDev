#ifndef TTY_H
#define TTY_H

#include <stdint.h>

#define TERM_WIDTH 80
#define TERM_HEIGHT 25

#define BLACK       0x0
#define BLUE        0x1
#define GREEN       0x2
#define CYAN        0x3
#define RED         0x4
#define MAGENTA     0x5
#define BROWN       0x6
#define LIGHT_GRAY  0x7
#define DARK_GRAY   0x8
#define LIGHT_BLUE  0x9
#define LIGHT_GREEN 0xa
#define LIGHT_CYAN  0xb
#define LIGHT_RED   0xc
#define PINK        0xd
#define YELLOW      0xe
#define WHITE       0xf

uint16_t* init_terminal();

#endif
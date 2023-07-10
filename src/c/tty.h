#ifndef TTY_H
#define TTY_H

#include <stdint.h>

// Constants
#define TERM_WIDTH 80
#define TERM_HEIGHT 25

#define WHITE 0
#define BLACK 1

// Function declarations
void init_terminal(uint16_t* vga_buf);

#endif /* TTY_H */
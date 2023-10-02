#include "tty.h"
#include "stdio.h"

int fg_color = LIGHT_GRAY;
int bg_color = BLACK;

void init_terminal() {
    // Initialize the VGA buffer
    uint16_t* buffer = (uint16_t*) VGA_BUFFER;
    for (int i = 0; i < TERM_WIDTH * TERM_HEIGHT; i++) {
        buffer[i] = ' ' | (fg_color << 8) | (bg_color << 12);
    }
}
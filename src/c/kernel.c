#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "tty.h"

int fg_color = WHITE;
int bg_color = BLACK;

extern void enable_paging(uint32_t* dir);

void kernel_main() {
  puts("kernel_main()\n");

  uint32_t page_directory[1024] __attribute__((aligned(4096)));
  for (int i = 0; i < 1024; i++)
    page_directory[i] = 2;

  // Identity map first 1MB of RAM
  uint32_t page_table[1024] __attribute__((aligned(4096)));
  for (int i = 0; i < 1023; i++) {
    page_table[i] = (i * 0x1000) | 3;
  }

  page_directory[0] = ((uintptr_t)page_table) | 3;
  puts("enabling paging...\n");
  enable_paging(page_directory);
}
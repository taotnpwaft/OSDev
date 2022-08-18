; Constants for the multiboot header
MBALIGN     equ 1 << 0
MEMINFO     equ 1 << 1
MBFLAGS       equ MBALIGN | MEMINFO
MAGIC       equ 0x1BADB002
CHECKSUM    equ -(MAGIC + MBFLAGS)

; The actual multiboot header
section   .multiboot
align     4
dd        MAGIC
dd        MBFLAGS
dd        CHECKSUM

; Creating space for the stack. We will use these labels later
; to intilialize ebp and esp. 16 byte alined as per 
; the System V ABI
section     .bss
align       16
stack_base:
resb        16384
stack_pointer:  

section   .text
global    _start
_start:
  mov esp, stack_pointer

  extern kernel_main
  call kernel_main

  cli
.hang:
  hlt
  jmp .hang
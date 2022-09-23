; Constants for the multiboot header
MBALIGN     equ 1 << 0
MEMINFO     equ 1 << 1
MBFLAGS     equ MBALIGN | MEMINFO
MAGIC       equ 0x1BADB002
CHECKSUM    equ -(MAGIC + MBFLAGS)

extern puts
extern putc
extern kernel_main
extern init_terminal

; The actual multiboot header
section   .multiboot
align     4
dd        MAGIC
dd        MBFLAGS
dd        CHECKSUM

section     .data
align       4
VGA_BUFFER  equ 0xb8000

section     .rodata
align       4
message:    db 'boot.asm', 0xa, 0

; Creating space for the stack. We will use these labels later
; to intilialize ebp and esp. 16 byte alined as per 
; the System V ABI
section     .bss
align       4
stack_base: resb        16384
stack_pointer:  

section   .text
align     4
global    _start
_start:
  mov esp, stack_pointer

  push ebp
  mov ebp, esp
  push VGA_BUFFER
  call init_terminal
  add esp, 0x4
  pop ebp

  push ebp
  mov ebp, esp
  push VGA_BUFFER
  push message
  call puts
  add esp, 0x8
  pop ebp

  push ebp
  mov ebp, esp
  push VGA_BUFFER
  call kernel_main
  add esp, 0x4
  pop ebp

  cli
.hang:
  hlt
  jmp .hang

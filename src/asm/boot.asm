; Constants for the multiboot header
MBALIGN     equ 1 << 0
MEMINFO     equ 1 << 1
MBFLAGS     equ MBALIGN | MEMINFO
MAGIC       equ 0x1BADB002
CHECKSUM    equ -(MAGIC + MBFLAGS)

extern puts
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
message:    db '_start', 0xa, 0
paging_message:    db 'enabling paging', 0xa, 0

; Creating space for the stack. We will use these labels later
; to initialize ebp and esp. 16 byte aligned as per
; the System V ABI
section     .bss
align       4
stack_base: resb  (2048 * 1024) ; 2MB
stack_pointer:

section   .text
align     4

global enable_paging
enable_paging:
  push ebp
  mov ebp, esp

  mov eax, [ebp+8]
  mov cr3, eax
  mov eax, cr0
  or eax, 0x80000000
  mov cr0, eax

  pop ebp
  ret

global _start
_start:
  mov ebp, stack_base
  mov esp, stack_pointer

  push VGA_BUFFER
  call init_terminal

  push VGA_BUFFER
  push message
  call puts

  push VGA_BUFFER
  call kernel_main

  cli
  jmp .hang
.hang:
  hlt
  jmp .hang

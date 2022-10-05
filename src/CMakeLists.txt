add_executable(
  kernel
  
  ${PROJECT_SOURCE_DIR}/src/asm/boot.asm

  ${PROJECT_SOURCE_DIR}/src/c/kernel.c
  ${PROJECT_SOURCE_DIR}/src/c/stdio.c
  ${PROJECT_SOURCE_DIR}/src/c/stdlib.c
  ${PROJECT_SOURCE_DIR}/src/c/string.c
  ${PROJECT_SOURCE_DIR}/src/c/tty.c
)

set(SYSROOT CACHE STRING "sysroot")
set(SYS_INCLUDE CACHE STRING "/usr/include") # This path is relative to sysroot

target_include_directories(kernel PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_ASM_FLAGS "-f elf32 -o boot.o")

message(STATUS "---- ${CMAKE_ASM_FLAGS} ----")
message(STATUS "---- ${CMAKE_ASM_DEBUG} ----")
message(STATUS "---- ${CMAKE_ASM_MINSIZEREL} ----")
message(STATUS "---- ${CMAKE_ASM_RELWITHDEBINFO} ----")

set(CMAKE_C_FLAGS "-isystem=${SYS_INCLUDE} --sysroot=${SYSROOT} -std=gnu99 -ffreestanding -Wall -Wextra -c")
set(CMAKE_EXE_LINKER_FLAGS "-T linker.ld -Wl,-Map=kernel.map -o bin/kernel.bin -ffreestanding -nostdlib")

if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
  message(STATUS "---- Found Clang ----")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target i386-none-elf")
endif()

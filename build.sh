#!/bin/bash

# I plan to write a Makefile once the size of the project permits doing do.
# For now, a simple build script is more than sufficient. The project is so
# simple that the whole thing compiles almost instantly.

# Be warned, I have no idea how to write a shell script :)

export ASM_SRC_DIR="src/asm/*.asm"
export C_SRC_DIR="src/c/*.c"
export OBJ_DIR="*.o"
export SYSROOT="sysroot"
export SYS_INCLUDE="/usr/include" # This path is relative to sysroot
export LOCAL_INCLUDE="include"

export GCC="/home/joey/bin/bin/i686-elf-gcc"
export CC_FLAGS="-isystem=$SYS_INCLUDE --sysroot=$SYSROOT -I$LOCAL_INCLUDE -std=gnu99 -ffreestanding -Wall -Wextra -c"
export LINKER_FLAGS="-isystem=$SYS_INCLUDE --sysroot=$SYSROOT -T linker.ld -Wl,-Map=kernel.map -I$LOCAL_INCLUDE -o bin/kernel.bin -ffreestanding -nostdlib"
export CLANG_TARGET="-target i386-none-elf"

if [ "$1" == "clean" ]
then
  rm -rf *.o
  rm -rf bin/*.bin
  rm -rf iso/bin/kernel.bin
  exit
else
  nasm -f elf32 $ASM_SRC_DIR -o boot.o &&
  if [ "$1" == "clang" ]
  then
    clang $CLANG_TARGET $CC_FLAGS $C_SRC_DIR &&
    clang $CLANG_TARGET $LINKER_FLAGS $OBJ_DIR &&
    rm -rf *.o
  elif [ "$1" == "gcc" ]
  then
    $GCC $CC_FLAGS $C_SRC_DIR &&
    $GCC $LINKER_FLAGS $OBJ_DIR &&
    rm -rf *.o
  else
    echo "Invalid option \"$1\""
    exit
  fi
fi

cp bin/kernel.bin iso/bin
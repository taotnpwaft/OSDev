# OSDev

This is a OSDev project

Resources:

<https://wiki.osdev.org/Tutorials>

<https://www.reddit.com/r/osdev/>

<https://github.com/topics/osdev>

<https://gitlab.com/explore/projects/topics/osdev>

<https://stackoverflow.com/questions/tagged/osdev>

<https://groups.google.com/g/embeddednewbies/c/-eAcJMaTr24>

## Build Instructions

This skeleton project can be built with

- orindary `clang` or,
- `gcc` that targets a generic i386-elf platform.

To build, simply run `./build.sh clang` or `./build.sh gcc`. This will give you `bin/kernel.bin`, which can be made into an ISO with `mkiso.sh`. Alternatively, you can pass `-kernel bin/kernel.bin` to QEMU.

Once executed, the "kernel" will print 80 * 25 `a`'s to the VGA buffer.

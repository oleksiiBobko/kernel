#!/bin/bash

set -e
set -v

CFLAGS="-fno-builtin -nostdinc -O2 -I. -Wall -Werror"
LDFLAGS="-nostdlib -Wl,-N -Wl,-Ttext -Wl,100000 -Wl,--build-id=none"
gcc $CFLAGS -c kernel.c
gcc $CFLAGS -c boot.S
gcc $LDFLAGS -o kernel.exec boot.o kernel.o
objcopy -O binary kernel.exec kernel

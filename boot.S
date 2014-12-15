#define ASM 1

#include <multiboot.h>

.text
.code32
.global start, _start

start:
_start:

        jmp multiboot_entry
        .align 4
multiboot_header:

	.long MULTIBOOT_HEADER_MAGIC
	.long MULTIBOOT_HEADER_FLAGS
	.long -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
	.long multiboot_header
	.long _start
	.long _edata
	.long _end
	.long multiboot_entry

multiboot_entry:
	movl $(stack + STACK_SIZE), %esp
	
	pushl $0
	popf
	
	pushl %ebx
	pushl %eax

	call EXT_C(kmain)

loop: hlt
	jmp loop

	.comm stack, STACK_SIZE
	

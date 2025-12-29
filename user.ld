ENTRY(start)

SECTIONS {
    . = 0x1000000;

    /* machine code */
    .text :{
        KEEP(*(.text.start));
        *(.text .text.*);
    }

    /* read-only data */
    .rodata : ALIGN(4) {
        *(.rodata .rodata.*);
    }

    /* Data with initial values */
    .data : ALIGN(4) {
        *(.data .data.*);
    }

    /* Data that should be zero-filled at startup */
    .bss : ALIGN(4) {
        *(.bss .bss.* .sbss .sbss.*);

        . = ALIGN(16);
        . += 64 * 1024; /* 64 KB */
        __stack_top = .;

        ASSERT(. < 0x1800000, "executable is too large");
    }
}
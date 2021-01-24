ENTRY(reset_handler)

MEMORY {
    ROM (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .vctr : {
        *(.vctr)
    } > ROM
    .text : { 
        *(.text)
    } > ROM
    .data : {
        _data_start = .;
        *(.data)
        . = ALIGN(4);
        _data_end = .;
    } > RAM AT> ROM
    .bss : {
        _bss_start = .;
        *(.bss)
        . = ALIGN(4);
        _bss_end = .;
    } > RAM
    _lma_data = LOADADDR(.data);
}
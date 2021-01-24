ENTRY(reset_handler)

MEMORY {
    FLASH (rx): ORIGIN = 0x08000000, LENGTH = 64K
    SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .vctr : {
        *(.vctr)
    } > FLASH
    .text : { 
        *(.text)
    } > FLASH

    _lma_data = LOADADDR(.data);
    
    .data : {
        _data_start = .;
        *(.data)
        . = ALIGN(4);
        _data_end = .;
    } > SRAM AT> FLASH
    .bss : {
        _bss_start = .;
        *(.bss)
        . = ALIGN(4);
        _bss_end = .;
    } > SRAM
}
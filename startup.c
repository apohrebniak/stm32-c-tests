//
// Created by npe on 20.01.21.
//
#include <stdint.h>

#define SRAM_START 0x20000000
#define SRAM_END 0x3FFFFFFF
#define STACK_START SRAM_END

extern uint8_t _data_start;
extern uint8_t _data_end;
extern uint8_t _bss_start;
extern uint8_t _bss_end;

extern uint8_t _lma_data;

void reset_handler(void);
void noop_handler(void);
void main(void);

uint32_t vector_table[] __attribute__ ((section (".vctr"))) = {
        STACK_START,
        (uint32_t) reset_handler,
        (uint32_t) noop_handler, //NMI
        (uint32_t) noop_handler, //Hard Fault
        (uint32_t) noop_handler, //MM Fault
        (uint32_t) noop_handler, //Bus Fault
        (uint32_t) noop_handler, //Usage Fault
        0, 0, 0, 0,
        (uint32_t) noop_handler, //SVCall
        0, 0,
        (uint32_t) noop_handler, //PendSV
        (uint32_t) noop_handler, //Systick
        (uint32_t) noop_handler, //IRQ0
        (uint32_t) noop_handler, //IRQ1
        (uint32_t) noop_handler, //IRQ2
        (uint32_t) noop_handler, //IRQ3
        (uint32_t) noop_handler, //IRQ4
        (uint32_t) noop_handler, //IRQ5
        (uint32_t) noop_handler, //IRQ6
        (uint32_t) noop_handler, //IRQ7
        (uint32_t) noop_handler, //IRQ8
        (uint32_t) noop_handler, //IRQ9
        (uint32_t) noop_handler, //IRQ10
        (uint32_t) noop_handler, //IRQ11
        (uint32_t) noop_handler, //IRQ12
        (uint32_t) noop_handler, //IRQ13
        (uint32_t) noop_handler, //IRQ14
        (uint32_t) noop_handler, //IRQ15
        (uint32_t) noop_handler, //IRQ16
        (uint32_t) noop_handler, //IRQ17
        (uint32_t) noop_handler, //IRQ18
        (uint32_t) noop_handler, //IRQ19
        (uint32_t) noop_handler, //IRQ20
        (uint32_t) noop_handler, //IRQ21
        (uint32_t) noop_handler, //IRQ22
        (uint32_t) noop_handler, //IRQ23
        (uint32_t) noop_handler, //IRQ24
        (uint32_t) noop_handler, //IRQ25
        (uint32_t) noop_handler, //IRQ26
        (uint32_t) noop_handler, //IRQ27
        (uint32_t) noop_handler, //IRQ28
        (uint32_t) noop_handler, //IRQ29
        (uint32_t) noop_handler, //IRQ30
        (uint32_t) noop_handler, //IRQ31
        (uint32_t) noop_handler, //IRQ32
        (uint32_t) noop_handler, //IRQ33
        (uint32_t) noop_handler, //IRQ34
        (uint32_t) noop_handler, //IRQ35
        (uint32_t) noop_handler, //IRQ36
        (uint32_t) noop_handler, //IRQ37
        (uint32_t) noop_handler, //IRQ38
        (uint32_t) noop_handler, //IRQ39
        (uint32_t) noop_handler, //IRQ40
        (uint32_t) noop_handler, //IRQ41
        (uint32_t) noop_handler, //IRQ42
        (uint32_t) noop_handler, //IRQ43
        (uint32_t) noop_handler, //IRQ44
        (uint32_t) noop_handler, //IRQ45
        (uint32_t) noop_handler, //IRQ46
        (uint32_t) noop_handler, //IRQ47
        (uint32_t) noop_handler, //IRQ48
        (uint32_t) noop_handler, //IRQ49
        (uint32_t) noop_handler, //IRQ50
        (uint32_t) noop_handler, //IRQ51
        (uint32_t) noop_handler, //IRQ52
        (uint32_t) noop_handler, //IRQ53
        (uint32_t) noop_handler, //IRQ54
        (uint32_t) noop_handler, //IRQ55
        (uint32_t) noop_handler, //IRQ56
        (uint32_t) noop_handler, //IRQ57
        (uint32_t) noop_handler, //IRQ58
        (uint32_t) noop_handler, //IRQ59
        (uint32_t) noop_handler, //IRQ60
        (uint32_t) noop_handler, //IRQ61
        (uint32_t) noop_handler, //IRQ62
        (uint32_t) noop_handler, //IRQ63
        (uint32_t) noop_handler, //IRQ64
        (uint32_t) noop_handler, //IRQ65
        (uint32_t) noop_handler, //IRQ66
        (uint32_t) noop_handler  //IRQ67
};

void noop_handler() {
    while (1) {}
}

void reset_handler() {
     // copy .data
     uint8_t *p_dst = (uint8_t*)&_data_start;
     uint8_t *p_src = (uint8_t*)&_lma_data;
     while (p_dst != (uint8_t*)&_data_end)
     {
         *p_dst++ = *p_src++;
     }
     
     // init bss
     p_dst = (uint8_t*)&_bss_start;
     while (p_dst != (uint8_t*)&_bss_end)
     {
         *p_dst++ = 0;
     }
     
     main();
}


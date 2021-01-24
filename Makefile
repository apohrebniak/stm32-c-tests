CC= arm-none-eabi-gcc
LD= arm-none-eabi-ld
CC_FLAGS= -c -mtune=cortex-m3 -mthumb -mfloat-abi=soft -std=gnu11 -Werror -O0
LD_FLAGS= -T link.ld -Map final.map

all: main.o startup.o final.elf

#compile and assemble. do not link
main.o: main.c
	$(CC) $(CC_FLAGS) -o  $@ $^

startup.o: startup.c

	$(CC) $(CC_FLAGS) -o  $@ $^

final.elf:
	$(LD) $(LD_FLAGS) -o $@ *.o

clean:
	rm -rf *.o *.elf *.map

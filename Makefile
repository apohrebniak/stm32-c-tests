CC= arm-none-eabi-gcc
LD= arm-none-eabi-ld
CC_FLAGS= -mtune=cortex-m3 -mthumb -Werror -o0
LD_FLAGS= -T link.ld -Map final.map

all: main.o startup.o final.elf

#compile and assemble. do not link
main.o: main.c
	$(CC) $(CC_FLAGS) -c -o  $@ $^

startup.o: startup.c

	$(CC) $(CC_FLAGS) -c -o  $@ $^

final.elf:
	$(LD) $(LD_FLAGS) -o $@ *.o

clean:
	rm -rf *.o *.elf *.map

CC= /home/npe/etc/arm-none-eabi/bin/arm-none-eabi-gcc
CC_FLAGS= -mtune=cortex-m3 -mthumb -Werror

all: main.o startup.o

#compile and assemble. do not link
main.o: main.c
	$(CC) $(CC_FLAGS) -c -o  $@ $^

startup.o: startup.c
	$(CC) $(CC_FLAGS) -c -o  $@ $^

clean:
	rm -rf *.o *.elf

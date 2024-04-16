CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99
OBJS = prog.o increment.o decrement.o

.PHONY: all bin clean

all: bin

bin: $(OBJS)
	gcc $(CFLAGS) -o prog.bin $(OBJS)

decrement.o: decrement.c decrement.h globals.h
	gcc $(CFLAGS) -c decrement.c

increment.o: increment.c increment.h globals.h
	gcc $(CFLAGS) -c increment.c

prog.o: prog.c globals.h increment.h decrement.h
	gcc $(CFLAGS) -c prog.c

clean:
	@echo "cleaning up generated files"
	-rm -f prog.bin $(OBJS)

CC=gcc
CFLAGS=-Wall -ansi
DEPS=test.h exo.h
OBJ=main.o test.o exo.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bench: $(OBJ)
	gcc -o $@ $^

.PHONY: clean

run:
	./bench -a
	
clean:
	rm -f *.o bench
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic
LDFLAGS=-lm
DEPS=event.h customer.h queue.h prioqueue.h
OBJ=event.o customer.o queue.o prioqueue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bakery: bakery.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) bakery

run: bakery
	./bakery
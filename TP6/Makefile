CC=gcc
CFLAGS=-std=c99 -Wall -Werror
LDFLAGS=
DEPS=list.h
OBJ=list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

concordance: concordance.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) concordance
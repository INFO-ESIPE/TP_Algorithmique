CC=gcc
CFLAGS=-std=c99 -Wall -Werror
LDFLAGS=
DEPS=visualtree.h tree.h bst.h
OBJ=visualtree.o tree.o bst.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) main main.o current-tree.dot current-tree.pdf

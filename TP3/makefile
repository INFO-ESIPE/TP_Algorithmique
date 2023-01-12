CC=gcc
CFLAGS=-Wall -ansi -pedantic 
CFLAGSP=-Wall -ansi
MLVFLAGS=-lMLV -lm
LDFLAGS=
OBJ=build/main.o build/exo1.o build/frame.o build/grid.o build/draw.o build/sweeper.o build/draw_plate.o build/queen_chess.o

all: $(OBJ)
	$(CC) -o minesweeper $(OBJ) $(CFLAGS) $(MLVFLAGS)

build/main.o: main.c exo1_H/exo1.h exo2_Sweeper/sweeper.h exo4_Reines/queen_chess.h
	$(CC) -c main.c -o build/main.o $(CFLAGS) 

build/exo1.o: exo1_H/exo1.c exo1_H/frame.h
	$(CC) -c exo1_H/exo1.c -o build/exo1.o $(CFLAGS) $(MLVFLAGS)

build/frame.o: exo1_H/frame.c 
	$(CC) -c exo1_H/frame.c -o build/frame.o $(CFLAGS) $(MLVFLAGS)



build/draw.o: exo2_Sweeper/draw.c exo2_Sweeper/grid.h
	$(CC) -c exo2_Sweeper/draw.c -o build/draw.o $(CFLAGSP) $(MLVFLAGS)

build/sweeper.o: exo2_Sweeper/sweeper.c exo2_Sweeper/grid.h  exo2_Sweeper/draw.h
	$(CC) -c exo2_Sweeper/sweeper.c -o build/sweeper.o $(CFLAGSP) $(MLVFLAGS)

build/grid.o:exo2_Sweeper/grid.c exo2_Sweeper/draw.h
	$(CC) -c exo2_Sweeper/grid.c -o build/grid.o $(CFLAGSP) $(MLVFLAGS)


build/queen_chess.o: exo4_Reines/queen_chess.c exo4_Reines/draw_plate.h
	$(CC) -c exo4_Reines/queen_chess.c -o build/queen_chess.o $(CFLAGSP) 

build/draw_plate.o: exo4_Reines/draw_plate.c exo4_Reines/queen_chess.h
	$(CC) -c exo4_Reines/draw_plate.c -o build/draw_plate.o $(CFLAGSP) 

run:
	./minesweeper -a


clean: 
	rm -f build/*.o
	rm -f *~
	rm -f minesweeper

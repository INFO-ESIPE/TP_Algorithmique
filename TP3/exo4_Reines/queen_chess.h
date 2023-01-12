/*
	TP 3 d'algorithmique - exo5 
	Max Ducoudré - INFO1
*/

#ifndef QUEEN_CHESS_H
#define QUEEN_CHESS_H
#include "draw_plate.h"
#include "queen_algo.h"


struct CellData {
    int pos_x;
    int pos_y;
    int queen;
};

struct PlateData {
    int plate_size;
    int queen_count;
    struct CellData** cells;
    int* queen_board;

};



void start_chess_queen(int queen_count, int grid_size);

struct PlateData createEmptyPlate(int grid_size, int queen_count);
void freePlateData(struct PlateData plate_data);





#endif 
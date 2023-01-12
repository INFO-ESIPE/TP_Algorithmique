#ifndef QUEEN_CHESS_H
#define QUEEN_CHESS_H
#include "draw_plate.h"


struct CellData {
    int pos_x;
    int pos_y;
    int queen;
};

struct PlateData {
    int plate_size;
    struct CellData** cells;
};


void start_chess_queen(int queen_count, int grid_size);






#endif 
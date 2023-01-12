#ifndef DRAW_PLATE_H
#define DRAW_PLATE_H
#include <MLV/MLV_all.h>

#include "queen_chess.h"

#define CHESS_WIN_WIDTH 500
#define CHESS_WIN_HEIGHT 500


#define CHESS_BACKGROUND_COLOR MLV_COLOR_WHITE

#define CHESS_WHITE_CELL MLV_COLOR_WHITE
#define CHESS_BLACK_CELL MLV_COLOR_GRAY

#define SLOT_SIZE 30

struct PlateData;

void drawChessFrame();
void freeChessFrame();
void draw_plate(int x, int y, int cell_size, struct PlateData chess_plate);

#endif 
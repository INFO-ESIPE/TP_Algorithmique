/*
	TP 3 d'algorithmique - exo5 
	Max Ducoudré - INFO1
*/

#ifndef QUEEN_ALGO_H
#define QUEEN_ALGO_H

#include "queen_chess.h"
#include "draw_plate.h"

struct PlateData;

int conflict(int board[], int size, int pos);
int queens(int board[], int size, int pos,  struct PlateData plate_data);

#endif 
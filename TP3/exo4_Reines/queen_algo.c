/*
	TP 3 d'algorithmique - exo5 
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

#include "queen_algo.h"


int conflict(int board[], int size, int pos) {
	int i;
	for (i = 0; i < pos; i++) {
		if (board[i] == board[pos] ||
			(pos-i == board[pos]-board[i]) ||
			(pos-i == board[i]-board[pos]))
		return 1;
	}
	return 0;
}
int current_grid_x_offset = 0;
int current_grid_y_offset = -1;

int queens(int board[], int size, int pos, struct PlateData plate_data) {

	int little_slot_size = ((CHESS_WIN_HEIGHT/2)/size)/1.6;
	int little_grid_size = little_slot_size*plate_data.plate_size;
	
	if (pos == size) {
		if(current_grid_x_offset%3 == 0) {
			current_grid_y_offset++;
			current_grid_x_offset=0;
			};
		draw_plate(
			10+ (current_grid_y_offset * (little_grid_size+10)) , 
			10+(little_grid_size + 10) * (current_grid_x_offset) + 10, 
			little_slot_size, plate_data);
		current_grid_x_offset++;

		return 1;
	} else {
		int i, count = 0;
		for (i = 0; i < size; i++) 
		{
			board[pos] = i;
			if (!conflict(board, size, pos))
			count = count + queens(board, size, pos+1, plate_data);
		}

		return count;
	}
}
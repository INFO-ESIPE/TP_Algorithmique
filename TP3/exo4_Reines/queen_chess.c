#include <stdio.h>
#include <stdlib.h>

#include "queen_chess.h"

void start_chess_queen(int queen_count, int grid_size)
{
    int i,j;
    struct PlateData plate_data;
    struct CellData cell_data;

    printf("Find queen %d %d\n", queen_count, grid_size);

    drawChessFrame();

    plate_data.plate_size = grid_size;

    plate_data.cells = malloc(sizeof(struct CellData)*grid_size);
    for(i = 0; i < grid_size; i++)
        plate_data.cells[i] = malloc(sizeof(struct CellData)*grid_size);


    for(i = 0; i < grid_size; i++)
    {
        for(j = 0; j < grid_size; j++)
        {
            cell_data.pos_x = i;
            cell_data.pos_y = j;
            cell_data.queen = 0;
            plate_data.cells[i][j] = cell_data;
        }
    }

    draw_plate(1,1, CHESS_WIN_WIDTH/grid_size, plate_data);

    for(i = 0; i < grid_size; i++)
        free(plate_data.cells[i]);
    free(plate_data.cells);

    freeChessFrame();
}


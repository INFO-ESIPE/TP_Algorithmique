/*
	TP 3 d'algorithmique - exo5 
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

#include "queen_chess.h"

void start_chess_queen(int queen_count, int grid_size)
{
    if(queen_count>grid_size)
    {
        printf("With --queen_chess, N must be <= SIZE !\n");
        return;
    }
    struct PlateData plate_data;
    int possible_solutions = 0;
    drawChessFrame();

    printf("--Start Queen Algorithm with %d queens and %dx%d cells--\n", queen_count, grid_size,grid_size);

    plate_data = createEmptyPlate(grid_size, queen_count);
    possible_solutions = queens(plate_data.queen_board, plate_data.plate_size, 0, plate_data);
    printf("There is %d combinaisons for %d queens in %dx%d grid !\n", possible_solutions, queen_count, grid_size,grid_size);
    

    freeChessFrame(plate_data);    
    freeChessFrame();

}


struct PlateData createEmptyPlate(int grid_size, int queen_count)
{
    int i,j;
    struct PlateData plate_data;
    struct CellData cell_data;

    plate_data.plate_size = grid_size;
    plate_data.queen_count = queen_count;
    plate_data.cells = malloc(sizeof(struct CellData)*grid_size);
    for(i = 0; i < plate_data.plate_size; i++)
        plate_data.cells[i] = malloc(sizeof(struct CellData)*grid_size);


    for(i = 0; i < grid_size; i++) {
        for(j = 0; j < grid_size; j++) {
            cell_data.pos_x = i;
            cell_data.pos_y = j;
            cell_data.queen = 0;
            plate_data.cells[i][j] = cell_data;
        }
    }
    
    plate_data.queen_board = malloc(sizeof(int)*plate_data.queen_count);
    for(i = 0; i < plate_data.queen_count; i++)
        plate_data.queen_board[i] = i;
    

    return plate_data;
}

void freePlateData(struct PlateData plate_data)
{
    int i;
    /*free(plate_data.queen_board);*/
    for(i = 0; i < plate_data.plate_size; i++)
        free(plate_data.cells[i]);
    free(plate_data.cells);
}
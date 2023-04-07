/*
	TP 3 d'algorithmique - exo5 - Permet le dessin du plateau
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>


#include "draw_plate.h"

void draw_plate(int x, int y, int cell_size, struct PlateData plate_data)
{
    int i,j;
    MLV_Image *queen_image = MLV_load_image("exo4_Reines/queen.png");
    MLV_resize_image(queen_image, cell_size-4, cell_size-4);
    MLV_draw_filled_rectangle(x,y, cell_size*plate_data.plate_size, cell_size*plate_data.plate_size, CHESS_BACKGROUND_COLOR);

    for(i = 0; i < plate_data.plate_size; i++)
    {
        for(j = 0; j < plate_data.plate_size; j++)
        {
            plate_data.cells[i][j].queen = 0;

        }

    }

    for(i = 0; i < plate_data.queen_count; i++)
    {
        j = plate_data.queen_board[i];
        plate_data.cells[i][j].queen = 1;
    }
    

    for(i = 0; i < plate_data.plate_size; i++)
    {
        for(j = 0; j < plate_data.plate_size; j++)
        {
            if((j+i)%2 == 0)
                MLV_draw_filled_rectangle(x + (i*cell_size), y + (j*cell_size), cell_size, cell_size, CHESS_BLACK_CELL);
            else
                MLV_draw_filled_rectangle(x + (i*cell_size), y + (j*cell_size), cell_size, cell_size, CHESS_WHITE_CELL);
            
            MLV_draw_rectangle(x + (i*cell_size), y + (j*cell_size), cell_size, cell_size, MLV_COLOR_BLACK);
            if(plate_data.cells[i][j].queen == 1)
            {                
                MLV_draw_image(queen_image,  x + (i*cell_size) +2, y + (j*cell_size) +2);
            }
        }
    }

    MLV_free_image(queen_image);

	MLV_update_window();

}

void drawResultText(int grid_size, int queen_nb, int solution_nb)
{
    char text[255];
    sprintf(text, "There is %d solutions for a %dx%d grid with %d queens !", solution_nb, grid_size,grid_size, queen_nb);
    MLV_draw_text(CHESS_WIN_WIDTH/3, 2, text, MLV_COLOR_BLACK);
    MLV_update_window();
}

void drawChessFrame(){
	MLV_create_window("N Reines", "N Reines", CHESS_WIN_WIDTH, CHESS_WIN_HEIGHT);
	MLV_draw_filled_rectangle(0, 0, CHESS_WIN_WIDTH, CHESS_WIN_HEIGHT, CHESS_BACKGROUND_COLOR);
	MLV_update_window();

}
void freeChessFrame()
{

    MLV_wait_seconds(30);
	MLV_free_window();
}
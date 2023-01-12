#include <stdio.h>
#include <stdlib.h>

#include "draw_plate.h"

void draw_plate(int x, int y, int cell_size, struct PlateData plate_data)
{
    int i,j;
    MLV_draw_filled_rectangle(x,y, cell_size*plate_data.plate_size, cell_size*plate_data.plate_size, CHESS_BACKGROUND_COLOR);

    for(i = 0; i < plate_data.plate_size; i++)
    {
        for(j = 0; j < plate_data.plate_size; j++)
        {

            if((j+i)%2 == 0)
                MLV_draw_filled_rectangle(x + (i*cell_size), y + (j*cell_size), cell_size, cell_size, CHESS_BLACK_CELL);
            else
                MLV_draw_filled_rectangle(x + (i*cell_size), y + (j*cell_size), cell_size, cell_size, CHESS_WHITE_CELL);
            
            MLV_draw_rectangle(x + (i*cell_size), y + (j*cell_size), cell_size, cell_size, MLV_COLOR_BLACK);

        }
    }

    printf("draw_plate\n");
	MLV_update_window();

}

void drawChessFrame(){
	MLV_create_window("N Reines", "N Reines", CHESS_WIN_WIDTH, CHESS_WIN_HEIGHT);
	MLV_draw_filled_rectangle(0, 0, CHESS_WIN_WIDTH, CHESS_WIN_HEIGHT, CHESS_BACKGROUND_COLOR);
	MLV_update_window();

}
void freeChessFrame()
{

    MLV_wait_seconds(10);
	MLV_free_window();
}
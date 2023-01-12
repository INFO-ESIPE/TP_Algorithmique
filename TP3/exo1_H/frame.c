/*
	TP 3 d'algorithmique - Permet de gérer la fenêtre de la libmlv
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

#include "frame.h"

void createFrame(char* gridName)
{
	MLV_create_window(gridName, gridName, WIN_WIDTH, WIN_HEIGHT);
	MLV_draw_filled_rectangle(0, 0, WIN_WIDTH, WIN_HEIGHT, BACKGROUND_COLOR);
	MLV_update_window();


}

void freeFrame(int timeout)
{
	MLV_wait_seconds(timeout);
	MLV_free_window();
}
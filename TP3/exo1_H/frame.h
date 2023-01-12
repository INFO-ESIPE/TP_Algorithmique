/*
	TP 3 d'algorithmique - Permet de gérer la fenêtre de la libmlv
	Max Ducoudré - INFO1
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <MLV/MLV_all.h>


/*LIBMLB colors*/
#define LINE_COLOR MLV_COLOR_BLUE
#define BACKGROUND_COLOR MLV_COLOR_WHITE

#define WIN_HEIGHT 500
#define WIN_WIDTH 500

void createFrame(char* win_name);
void freeFrame(int timeout);

#endif
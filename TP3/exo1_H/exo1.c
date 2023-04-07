/*
	TP 3 d'algorithmique - H (exo1)
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>

#include "exo1.h"

/*Permet de lancer les tests de l'exercice 1*/
void start_exo1_test()
{
	createFrame("H - exo1");
	drawH(WIN_WIDTH/2, WIN_HEIGHT/2, WIN_WIDTH/2);
	freeFrame(5);
}



/*Fonction qui dessine un H ayant pour centre x & y et pour taille width*/
void drawH(int x, int y, int width)
{
	if(width > 4)
	{
		/*Dessin du H principal*/
		MLV_draw_line(x-width/2, y-width/2, x-width/2, y+width/2, LINE_COLOR);
		MLV_draw_line(x-width/2, y, x+width/2, y, LINE_COLOR);
		MLV_draw_line(x+width/2, y-width/2, x+width/2, y+width/2, LINE_COLOR);

		MLV_wait_milliseconds(50); /*Permet d'afficher les H au fur et à mesure */
		MLV_update_window();

		/*Dessin des 4 petits H*/
		drawH(x-width/2, y-width/2, width/2);
		drawH(x+width/2, y-width/2, width/2);
		drawH(x-width/2, y+width/2, width/2);
		drawH(x+width/2, y+width/2, width/2);

	}
}

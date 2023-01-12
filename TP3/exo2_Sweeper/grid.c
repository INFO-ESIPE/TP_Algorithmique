#include "grid.h"
#include "draw.h"
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include <time.h>


int debug_mode = 0;
void enableDebugMode() { debug_mode = 1;}

/*
 * Allocate memory for a grid and initialize each cell.
 */
grid *create_grid(int x_size, int y_size) {
	int i, j;
	grid *g = (grid *)malloc(sizeof(grid));
	g->x_size = x_size;
	g->y_size = y_size;
	g->cells = (cell **)malloc(x_size*sizeof(cell *));
	for (i = 0; i < x_size; i++)
		g->cells[i] = (cell *)malloc(y_size*sizeof(cell));

	for (j = 0; j < y_size; j++)
		for (i = 0; i < x_size; i++) {
			g->cells[i][j].x_pos = i;
			g->cells[i][j].y_pos = j;
			g->cells[i][j].visible = 0;
			g->cells[i][j].marked = 0;
			g->cells[i][j].mine = 0;
			g->cells[i][j].mine_count = 0;
		}

	return g;
}

/*
 * Free memory for a grid.
 */
void free_grid(grid *g) {
	int i;
	for (i = 0; i < g->x_size; i++)
		free(g->cells[i]);
	free(g->cells);
	free(g);
}

/*
 * Set all cells to visible (for debugging).
 */
void set_all_visible(grid *g) {
	int x, y;
	for (x = 0; x < g->x_size; x++)
		for (y = 0; y < g->y_size; y++)
			g->cells[x][y].visible = 1;
}

/*
 * Add exactly n mines to grid g in random positions.
 */
void add_mines(grid *g, int n) {
	int randX;
	int randY;

	if(n == 0) return; 

	while(1)
	{
		randX = rand() % g->x_size;
		randY = rand() % g->y_size;

		if(g->cells[randX][randY].mine == 0)
		{
			g->cells[randX][randY].mine = 1;
			g->cells[randX][randY].mine_count++;

			if(randX+1 < g->x_size && randY +1 < g->y_size)
				g->cells[randX+1][randY+1].mine_count++;

			if(randX-1 >= 0 && randY-1 >= 0)
				g->cells[randX-1][randY-1].mine_count++;

			if(randX-1 >= 0 && randY+1  < g->y_size )
				g->cells[randX-1][randY+1].mine_count++;

			if(randX+1 < g->x_size && randY-1  >= 0)
				g->cells[randX+1][randY-1].mine_count++;

			if(randX+1 < g->x_size)
				g->cells[randX+1][randY].mine_count++;
			if(randX-1 >= 0)
				g->cells[randX-1][randY].mine_count++;

			if(randY+1 < g->x_size)
				g->cells[randX][randY+1].mine_count++;
			if(randY-1 >= 0)
				g->cells[randX][randY-1].mine_count++;

			break;
		}
	}

	add_mines(g, n-1);
	return;
}

/*
 * Uncover cell c in grid g.
 * Return the total number of cells uncovered.
 */
int uncover(grid *g, cell *c) {
	
	int uncovered_count = 0;

	/*On vérifie si la case est jouable */
	if(c->visible == 1 || c->marked == 1)
		return 0;

	/*Si elle est jouable, on la dévoile & on actualise l'affichage*/
	c->visible = 1;
	draw_cell_actualise_window(c);
	if(debug_mode) MLV_wait_milliseconds(50);


	/* Gestion du cas où c'est une mine qui est découverte */
	if(c->mine == 1 || c->mine_count != 0)
	{
		return 1;
	}
	else
	{	
		/*Sinon, on appel récusrivement notre fonction pour toutes les cases voisines */
		if(c->x_pos+1 < g->x_size)
			uncovered_count += uncover(g, &g->cells[c->x_pos+1][c->y_pos]);
		if(c->x_pos-1 >= 0)
			uncovered_count += uncover(g, &g->cells[c->x_pos-1][c->y_pos]);

		if(c->y_pos+1 < g->y_size)
			uncovered_count += uncover(g, &g->cells[c->x_pos][c->y_pos+1]);
		if(c->y_pos-1 >= 0)
			uncovered_count += uncover(g, &g->cells[c->x_pos][c->y_pos-1]);

		if(c->x_pos+1 < g->x_size && c->y_pos+1 < g->y_size)
			uncovered_count += uncover(g, &g->cells[c->x_pos+1][c->y_pos+1]);

		if(c->x_pos-1 >= 0 && c->y_pos-1 >= 0)
			uncovered_count += uncover(g, &g->cells[c->x_pos-1][c->y_pos-1]);

		if(c->x_pos-1 >= 0 && c->y_pos+1 < g->y_size)
			uncovered_count += uncover(g, &g->cells[c->x_pos-1][c->y_pos+1]);

		if(c->x_pos+1 < g->x_size && c->y_pos-1 >= 0)
			uncovered_count += uncover(g, &g->cells[c->x_pos+1][c->y_pos-1]);

	

		return uncovered_count;
	}

	return 0;
}

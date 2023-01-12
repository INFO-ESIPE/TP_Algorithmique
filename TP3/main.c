/*
	TP 3 d'algorithmique - Minesweeper
	Max Ducoudré - INFO1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exo1_H/exo1.h"
#include "exo2_Sweeper/sweeper.h"
#include "exo4_Reines/queen_chess.h"


void usage();

int main(int argc, char* argv[])
{

    if(argc == 2 && strcmp(argv[1], "--exo1") == 0){
        start_exo1_test();
        return EXIT_SUCCESS;
    } 
    else if(argc == 2 && strcmp(argv[1], "--sweeper") == 0)
    {
        start_sweeper(0);
        return EXIT_SUCCESS; 
    }
    else if(argc == 2 && strcmp(argv[1], "--test_add_mines") == 0)
    {
        start_sweeper(1);
        return EXIT_SUCCESS; 
    }
    else if(argc == 2 && strcmp(argv[1], "--test_uncover") == 0)
    {
        start_sweeper(2);
        return EXIT_SUCCESS; 
    }
    else if(argc == 4 && strcmp(argv[1], "--queen_chess") == 0)
    {
        start_chess_queen(atoi(argv[2]), atoi(argv[3]));
        return EXIT_SUCCESS; 
    }



    else if(argc == 2 && strcmp(argv[1], "-a") == 0)
    {
        start_exo1_test();
        start_sweeper(0);

        return EXIT_SUCCESS; 
    }


    usage();
    return EXIT_FAILURE;
}



void usage() {
	printf("Usage: ./minesweeper [options]\n");
    printf("  --exo1                Run tests for exo1.\n");
    printf("  --sweeper             Run the sweeper game.\n");
    printf("  --test_add_mines      Run the sweeper game and display all mines for debug.\n");
    printf("  --test_uncover        Use to test uncover mines function (uncover with wait).\n");
    printf("  --queen_chess N SIZE  Find solutions to places N queens in chess grid SIZE*SIZE width .\n");
	printf("\n");
}

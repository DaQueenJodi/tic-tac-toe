#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "input.h"

int main(int argc, char** argv) {
    bool AI = false;
    if (argc > 1) {
        AI = !strcmp(argv[1], "ai");
    }
    if (AI) {
        srand(time(NULL));
    }
    new_board(); // generate the board
    int player = 1;
    Point p;
    while (1) {
        if (!AI || player != 2) {
            String input = prompt(player);
            printf("\n");
            p = parse_input(input);
            if (p.x < 0 || p.y < 0) {
                printf("make sure to enter the coordinates correctly, ex: '1, 2', '1 2', '12' \n");
                continue;
            }
        }
        else {
            printf("\n");
            p = new_point((rand() % 2) + 1, (rand() % 3) + 1);
        }
        if (b[p.x][p.y] == 0) {
            b[p.x][p.y] = player; 
        }
        else {
            if (AI && player == 2) { 
                printf("square is already occupied! \n");
                continue;
            }
        }


        print_board(b);
        if (check_board(b, player)) {
            printf("player %d won! \n", player);
            break;
        }
        if (player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }
    }
    return 0;
}
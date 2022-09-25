#include "board.h"
#include <stdio.h>

bool check_board(board b, int player) {
    for (int x = 0; x < 3; x++) { // check collumns/rows
        int in_a_row = 0;
        int in_a_col = 0;
        for (int y = 0; y < 3; y++) {
            if (b[x][y] == player) {
                in_a_col += 1;
            }
            if (b[y][x] == player) {
                in_a_row += 1;
            }
        }
        if (in_a_row == 3) {
            return true;
        }
        if (in_a_col == 3) {
            return true;
        }
    }
    // check corners for diagonals
    int corner0 = 0;
    int corner1 = 0;
    
    for (int i = 0; i < 3; i++) {
        if (b[0 + i][0 + i] == player) {
            corner0 += 1;
        }
        if (b[2 - i][0 + i] == player) {
            
            corner1 += 1;
        }

    }
    if (corner0 == 3 || corner1 == 3) {
        return true;
    }


    return false;
}



Point new_point(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}



void print_board(board b) {
    for (int y = 0; y < 3; y++) {
        printf(" ");
        for (int x = 0; x < 3; x++) {
            int player = b[x][y];
            char c;
            switch (player) {
                case 0:
                    c = ' ';
                    break;
                case 1:
                    c = 'X';
                    break;
                case 2:
                    c = 'O';
                    break;
            }
            printf("%c", c);
            printf(" ");
            if (x != 2) {
                printf("| ");
            }
        }
        printf("\n");
        if (y != 2) {
            printf("---+---+---");
            printf("\n");
        }
    }
}











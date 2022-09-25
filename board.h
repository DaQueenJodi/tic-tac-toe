#pragma once
#include <stdbool.h>
#define PLUS  1
#define MINUS 2
#define NONE  0

#define new_board() board b; for (int x = 0; x < 3; x++) { for (int y = 0; y < 3; y++) { b[x][y] = 0; } }


typedef int board[3][3];

bool check_board(board b, int player);

typedef struct {
    int x;
    int y;
} Point;

Point new_point(int x, int y);


void print_board(board b);














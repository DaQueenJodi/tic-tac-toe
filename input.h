#pragma once
#include "board.h"

typedef struct {
    char* buff;
    int size;
} String;

String prompt();
Point parse_input(String input);
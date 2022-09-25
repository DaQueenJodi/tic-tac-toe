#include "input.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
Point parse_input(String input) {
    int x = -1;
    int y = -1;
    for (int i = 0; i < input.size; i++) {
        char c = input.buff[i];
        if (isalpha(c)) {
            return new_point(-1, -1);
        }
        if (c == ' ' || c == ',') {// skip spaces and commas
            continue;
        }
        if (x == -1) {
            x = c - '0'; // convert c to a digit
        }
        else if (y == -1){
            y = c - '0'; 
        }
        else {
            return new_point(-1, -1);
        }
}
    return new_point(x - 1, y - 1);
}

String prompt(int player) {
    printf("Enter your move, player %d: ", player);
    char *buff = malloc(3);
    memset(buff, 0, 3);
    int size = 0;
    int capacity = 3;
    while (1) {
        char c = fgetc(stdin);
        if (c == '\0' || c == '\n') {
            break;
        }
        if (size == capacity) {
            capacity *= 2;
            buff = realloc(buff, capacity);
        }
        buff[size] = c;
        size += 1;
    }
    String s;
    s.buff = buff;
    s.size = size;
    return s;
}






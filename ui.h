#ifndef UI_C
#define UI_C

#include "board.h"

typedef struct {
    int row;
    int col;
} Cursor;


void print_ui(int *input);
void print_board(const Board *b, Cursor *c);



#endif
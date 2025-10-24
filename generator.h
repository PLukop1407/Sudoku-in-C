#ifndef GENERATOR_H
#define GENERATOR_H

#include "board.h"

void copy_board(Board *src, Board *cpy);
int count_solutions_helper(Board *b, int row, int col);
int count_solutions(Board *b, int row, int col);
int generate_puzzle(Board *b, int row, int col); 
void remove_numbers(Board *b, int num_to_remove);


#endif
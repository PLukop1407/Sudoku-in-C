#include <stdio.h>
#include <stdlib.h>
#include "board.h"

// TODO: clean up board copying, random number attempts



void copy_board(Board *src, Board *cpy) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cpy->grid[i][j] = src->grid[i][j];
        }
    }
}

int count_solutions_helper(Board *b, int row, int col) {
    if (row == 9)
        return 1;
    if (col == 9)
        return count_solutions_helper(b, row + 1, 0);
    if (b->grid[row][col] != 0)
        return count_solutions_helper(b, row, col + 1);

    int solutions = 0;
    for (int num = 1; num <= 9; num++) {
        if (is_valid_move(b, row, col, num)) {
            b->grid[row][col] = num;
            solutions += count_solutions_helper(b, row, col +1);
            if (solutions > 1) {
                return solutions;
            }
            b->grid[row][col] = 0;
        }
    }
    return solutions;
}

int count_solutions(Board *b, int row, int col) {
    Board temp_board;
    copy_board(b, &temp_board);

    return (count_solutions_helper(&temp_board, row, col));
}

int generate_puzzle(Board *b, int row, int col) {
    if (row == 9)
        return 1;
    if (col == 9)
        return generate_puzzle(b, row + 1, 0);
    if (b->grid[row][col] != 0)
        return generate_puzzle(b, row, col + 1);
    
    for (int attempt = 0; attempt < 9; attempt++) {
        int num = (rand() % 9) + 1;
        if (is_valid_move(b, row, col, num)) {
            b->grid[row][col] = num;
            if (generate_puzzle(b, row, col +1)) {
                return 1;
            }
            b->grid[row][col] = 0;
        }
    }
    return 0;
}

void remove_numbers(Board *b, int num_to_remove) {
    int removed = 0;

    while (removed < num_to_remove) {
        int row = rand() % 9;
        int col = rand() % 9;

        if (b->grid[row][col] == 0)
            continue;
        
        int backup = b->grid[row][col];
        b->grid[row][col] = 0;

        if (count_solutions(b, 0, 0) != 1) {
            b->grid[row][col] = backup;
        }
        else {
            removed++;
        }
    }
}
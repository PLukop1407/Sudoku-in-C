#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "generator.h"

// Initialise empty board (0)
void init_board(Board *b) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            b->grid[row][col] = 0;
        }
    }
    generate_puzzle(b, 0, 0);
}

// Helper function for displaying board
void print_board(const Board *b, int hRow, int hCol) {
    system("cls");
    printf("\n");
    for (int row = 0; row < SIZE; row++) {
        if (row % 3 == 0 && row != 0) 
            printf(" -  -  -   -  -  -   -  -  - \n");
        for ( int col = 0; col < SIZE; col++) {
            if (col % 3 == 0 && col != 0) 
                printf("|");
            int val = b->grid[row][col];

            //Highlight selected cell
            if (row == hRow && col == hCol) {
                if (val == 0)
                    printf("\033[7m   \033[0m");
                else
                    printf("\033[7m %d \033[0m", val);
            } else {
                // Print ordinary cells (empty and values)
                if (val == 0)
                    printf("   ");
                else
                    printf(" %d ", val);
            }

        }
        printf("\n");
    }

}

void set_cell(Board *b, int row, int col, int num) {
    if (is_valid_move(b, row, col, num)) {
        b->grid[row][col] = num;
        printf("\nValid move.");
    }
    else 
        printf("\nInvalid move.");
}



int is_valid_move(const Board *b, int row, int col, int num) {
    if (num == 0) return 0;

    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (b->grid[row][i] == num)
            return 0;
    }

    // Check col
    for (int i = 0; i < SIZE; i++) {
        if (b->grid[i][col] == num)
            return 0;
    }

    // Check 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b->grid[startRow +i ][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}


int is_complete(const Board *b) {
    // Check for empty cells
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (b->grid[row][col] == 0)
                return 0;
        }
    }

    return 1;
}


void save_board(const char* filename, Board *b) {
// Writing binary with wb
FILE* file = fopen(filename, "wb");
if (!file) {
    perror("Error opening file");
    return;
}

fwrite(b->grid, sizeof(int), 81, file);
fclose(file);
}


void load_board(const char* filename, Board *b) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fread(b->grid, sizeof(int), 81, file);
    fclose(file);
}
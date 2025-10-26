#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "board.h"

void print_ui(int *input) {
        system("cls");
        printf("+----------------------+\n");
        printf("|         Sudoku       |\n");
        printf("+----------------------+\n");
        printf("\n");
        printf("1. Play game\n");
        printf("2. Load game\n");
        printf("3. Quit\n");
        printf("\n");
        printf("Enter an option: ");
        scanf("%d", input);
        printf("\n");
}


// Helper function for displaying board
void print_board(const Board *b, Cursor *c) {
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
            if (row == c->row && col == c->col) {
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

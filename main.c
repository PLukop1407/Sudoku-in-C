#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "board.h"
#include "generator.h"

// TODO: make UI.c / Game.c to handle UI / Game logic

void printUI(int *a) {
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
        scanf("%d", a);
        printf("\n");
}


void gameLoop(Board *b) {
    bool playing = true;
    int input;

    // Highlighted cell coordinates
    int hRow = 0;
    int hCol = 0;

    while(playing) {
        print_board(b, hRow, hCol);

        // Trying to read arrow key inputs but Windows puts special values in the buffer (0 || 224)
        int ch = getch();
        if (ch == 0 || ch == 224) {
            ch = getch();
                switch(ch) {
                    case 77:
                    //right
                        hCol = (hCol < 8) ? hCol + 1 : hCol;
                        break;
                    case 75:
                    //left
                        hCol = (hCol > 0) ? hCol - 1 : hCol;
                        break;
                    case 80:
                    //up
                        hRow = (hRow < 8) ? hRow + 1 : hRow;
                        break;
                    case 72:
                    //down
                        hRow = (hRow > 0) ? hRow - 1 : hRow;
                        break;
                }
            }
        }
    }


int main() {

    srand(time(NULL));
    bool running = true;
    int userInput;

    while(running) {
        printUI(&userInput);
        switch (userInput) {
            case 1:
                Board b;
                init_board(&b);
                remove_numbers(&b, 48);
                gameLoop(&b);
                break;
            case 2:
                printf("Picked load game");
                getch();
                break;
            case 3:
                running = false;
        }
    }

    return 0;
}
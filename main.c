#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "board.h"
#include "generator.h"
#include "ui.h"

// TODO: make UI.c / Game.c to handle UI / Game logic

void gameLoop(Board *b, Cursor *c) {
    bool playing = true;
    int input;

    while(playing) {
        print_board(b, c);

        // Trying to read arrow key inputs but Windows puts special values in the buffer (0 || 224)
        int ch = getch();
        if (ch == 0 || ch == 224) {
            ch = getch();
                switch(ch) {
                    case 77:
                    //right
                        c->col = (c->col < 8) ? c->col + 1 : c->col;
                        break;
                    case 75:
                    //left
                        c->col = (c->col > 0) ? c->col - 1 : c->col;
                        break;
                    case 80:
                    //up
                        c->row = (c->row < 8) ? c->row + 1 : c->row;
                        break;
                    case 72:
                    //down
                        c->row = (c->row > 0) ? c->row - 1 : c->row;
                        break;
                }
            } else if (ch == 27) { // ESC key
                printf("\nExiting game, press any key to continue...\n");
                getch();
                return;
            } else if (ch == 13 && b->grid[c->row][c->col] == 0) { // ENTER key && empty cell
                int input;
                printf("\nEnter a number for the highlighted cell: ");
                scanf("%d", &input); // TODO: input validation & move to UI/Game.c
                set_cell(b, c->row, c->col, input);
                getch();
            }
            //printf("\nASCII Value in ch: %d\n", ch);
            //getch();
        }
    }


int main() {

    srand(time(NULL));
    bool running = true;
    int userInput;

    while(running) {
        print_ui(&userInput);
        switch (userInput) {
            case 1:
                Board b;
                Cursor c = {0, 0};
                init_board(&b);
                remove_numbers(&b, 48);
                gameLoop(&b, &c);
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
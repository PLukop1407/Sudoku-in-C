#ifndef BOARD_H
#define BOARD_H

#define SIZE 9

typedef struct {
    int grid[SIZE][SIZE];
} Board;

void init_board(Board *b);
int is_valid_move(const Board *b, int row, int col, int num);
void set_cell(Board *b, int row, int col, int num);
int is_complete(const Board *b);
void save_board(const char* filename, Board *b);
void load_board(const char* filename, Board *b);

#endif
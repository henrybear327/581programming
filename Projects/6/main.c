/*
輸入N*N格子每個格子0~9表示cost，計算放8 queen的 maximum and minimum costs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

#define ALLOWED 0
#define FORBIDDEN 1
#define QUEEN 2

typedef struct {
    int board[SIZE][SIZE];
    int row;
} data;

void check_queen(data input)
{
    if(input.row == SIZE) {
        //print solution and count
    }

    for(int i = 0; i < SIZE; i++) {
        if(input.board[input.row][i] == ALLOWED) {
            input.board[input.row][i] = QUEEN; //queen coor. (input.row, i)

            //process board
            //row
            for(int index = 0; index < SIZE; index++) {
                if(input.board[input.row][index] != QUEEN) {
                    input.board[input.row][index] = FORBIDDEN;
                }
            }
            //column
            for(int index = 0; index < SIZE; index++) {
                if(input.board[index][i] != QUEEN) {
                    input.board[index][i] = FORBIDDEN;
                }
            }
            //diagnal
            int direction[4][2] = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}};


        }
    }
}

int count = 0;

int main()
{
    data initial;
    initial.row = 0;
    memset(initial.board, ALLOWED, sizeof(initial.board));
    /*
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d", initial.board[i][j]);
        }
        printf("\n");
    }
    */
    check_queen(initial);

    return 0;
}
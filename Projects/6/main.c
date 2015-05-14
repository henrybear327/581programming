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

int count = 0;

typedef struct {
    int board[SIZE][SIZE];
    int row;
} data;

void check_queen(data input_old)
{
    if(input_old.row == SIZE) {
        //print solution and count
        count++;
        printf("%d\n", count);
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                printf("%d", input_old.board[i][j]);
            }
            printf("\n");
        }

        return;
    }

    for(int i = 0; i < SIZE; i++) {
        if(input_old.board[input_old.row][i] == ALLOWED) {
            data input = input_old;
            input.board[input.row][i] = QUEEN; //queen coordinate (input.row, i)

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
            int row = input.row, column = i;
            for(int index = 1; index < SIZE; index++) {
                if(row - index >= 0 && column - index >= 0) //upper-left
                    input.board[row - index][column - index] = FORBIDDEN;
                if(row + index < SIZE && column - index >= 0)  //upper-right
                    input.board[row + index][column - index] = FORBIDDEN;
                if(row - index >= 0 && column + index < SIZE)  //lower-left
                    input.board[row - index][column + index] = FORBIDDEN;
                if(row + index < SIZE && column + index < SIZE)  //lower-right
                    input.board[row + index][column + index] = FORBIDDEN;
            }
            input.row++;
            check_queen(input);
            input.row--;
            input.board[input.row][i] = ALLOWED;
        }
    }
    return;
}

int main()
{
    data initial;
    initial.row = 0;
    memset(initial.board, ALLOWED, sizeof(initial.board));

    check_queen(initial);

    return 0;
}
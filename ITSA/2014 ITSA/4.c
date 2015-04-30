#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int starting_row, starting_column, color;
enum {is_white, is_black, is_two_color} flag;

void find_opening(int last_row, int last_column)
{
    if(column + 1 < 9 && input[last_row][column + 1] != walked_through) {
        if(input[last_row][column + 1] == white || input[last_row][column + 1] == black) {
            
        }
        input[last_row][last_column] = walked_through;
        find_opening(last_row, last_column + 1);
    }
    if(row - 1 >= 0 && input[last_row - 1][column] == space) {
        input[last_row][last_column] = walked_through;
        find_opening(last_row - 1, last_column);
    }
    if(column - 1 >= 0 && input[last_row][column - 1] == space) {
        input[last_row][last_column] = walked_through;
        find_opening(last_row, last_column - 1);
    }
    if(row + 1 < 9 && input[last_row + 1][column] == space) {
        input[last_row][last_column] = walked_through;
        find_opening(last_row + 1, last_column);
    }
    
    return;
}

int input[9][9];
enum {space, black, white, walked_through} token;

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases) {
            int row, column;
            for(row = 0; row < 9; row++) {
                for(column = 0; column < 9; column++) {
                    scanf("%d", &input[row][column]);
                }
            }

            for(row = 0; row < 9; row++) {
                for(column = 0; column < 9; column++) {
                    if(input[row][column] == space) {
                        starting_row = row;
                        starting_column = column;
                        find_opening(starting_row, starting_column);
                    }
                }
            }

        }
    }
    return 0;
}
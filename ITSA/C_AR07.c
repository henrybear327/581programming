#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int input[9][9];
    for(int row = 0; row < 9; row++)
        for(int column = 0; column < 9; column++)
            scanf("%d", &input[row][column]);

    for(int row = 0; row < 9; row++) {
        int record[10] = {0};
        for(int column = 0; column < 9; column++) {
            if(input[row][column] != 0 && record[input[row][column]] != 1)
                record[input[row][column]] = 1;
            else {
                printf("row%d #%d", column + 1, input[row][column]);
                break;
            }
        }
    }

    return 0;

}
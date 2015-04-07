#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
    /* This will get entire number down into one array element
    int input[9][9];
    for(int row = 0; row < 9; row++) {
        for(int column = 0; column < 9; column++) {
            scanf("%d", &input[row][column]);
            printf("row%d, column%d\n", row, column);
        }
        printf("Done row %d\n", row);
    }
    printf("Done!\n");
    */

    char input[11];
    int data[9][9], flag = 0, no_problem = 0;
    for(int row = 0; row < 9; row++) {
        fgets(input, 11, stdin);
        for(int column =0; column < 9; column++)
            data[row][column] = input[column] - '0';
    }

    int record[10] = {0}; /*come on!! it's 10*/
    for(int row = 0; row < 9; row++) {
        for(int column = 0; column < 9; column++) {
            if(record[data[row][column]] == 0 || data[row][column] == 0)
                record[data[row][column]]++;
            else {
                printf("row%d #%d\n", row + 1, data[row][column]);
                no_problem = 1;
                break;
            }
        }
        memset(record, 0, sizeof(record));
    }

    for(int column = 0; column < 9; column++) {
        for(int row = 0; row < 9; row++) {
            if(record[data[row][column]] == 0 || data[row][column] == 0)
                record[data[row][column]]++;
            else {
                printf("column%d #%d\n", column + 1, data[row][column]);
                no_problem = 1;
                break;
            }
        }
        memset(record, 0, sizeof(record));
    }

    int count = 0;
    while(count < 9) {
        int row, column, row_limit, column_limit;
        if(count < 3) {
            row = 0;
            column = count * 3;
        } else if(count < 6) {
            row = 3;
            column = (count - row) * 3;
        } else {
            row = 6;
            column = (count - row) * 3;
        }
        row_limit = row + 3;
        column_limit = column + 3;
        //printf("%d %d\n", row_limit, column_limit);

        for(int temp_row = row; temp_row < row_limit; temp_row++) {
            for(int temp_column = column; temp_column < column_limit; temp_column++) {
                //printf("%d %d %d\n", temp_row, temp_column, data[temp_row][temp_column]);
                //assert (data[temp_row][temp_column] <= 9);
                if(record[data[temp_row][temp_column]] == 0 || data[temp_row][temp_column] == 0) {
                    record[data[temp_row][temp_column]]++;
                } else {
                    printf("block%d #%d\n", count + 1, data[temp_row][temp_column]);
                    flag = 1;
                    no_problem = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        flag = 0;

        memset(record, 0, sizeof(record));
        count++;
    }

    if(no_problem == 0)
        printf("true\n");

    return 0;
}

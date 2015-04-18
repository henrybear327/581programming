/*
User輸入f, from,to,t計算函數f(x)在[from,to]區間的積分值, t為x變動量間隔, f是字串

Req:
1. 需使用pointer to function
2. 允許sin, cos,或其他庫存或自訂函數
3. 可判斷f是否是允許的函數
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char *valid_math_function[3] = {"sin", "cos", "tan"};

int parse_input(char *input)
{


    //Pass all tests
    return true;
}

//void integrate_function_in_lib();

int main()
{
    printf("<<Integration calculator>>\n");
    printf("Press q to terminate the program!\n");
    printf("=================================================================\n");
    while(1) {
        printf("Please enter in the order of function, from, to, interval: ");

        char input[1000];
        if(fgets(input, 1000, stdin) == NULL || ((strlen(input) == 2) && input[0] == 'q'))
            break;

        if(parse_input(input) == false) {
            printf("--> Illegal input.\n");
        } else {
            //perform integration

        }
    }

    printf("Thanks for using this program. Bye~~\n");

    return 0;
}
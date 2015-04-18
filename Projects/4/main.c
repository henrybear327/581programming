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

int check_input_function(char *input_function)
{
    if(strlen(input_function) == 1) {
        printf("\nError : No function is inputted.\n\n");
        return false;
    }
    return true;
}

int main()
{
    while(1) {
        printf("Please enter a function that's common(e.g. sin): ");
        char input_function[100];
        fgets(input_function, 100, stdin);
        if(check_input_function(input_function) == false)
            continue;
    }


    return 0;
}
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

double integrate_function(double (*function)(double), char *from, char *to, char *interval)
{
    double answer = 0;
    //printf("answer : %f\n", answer);

    double f_from = atof(from), f_to = atof(to), f_interval = atof(interval);
    //printf("%f %f %f\n", f_from, f_to, f_interval);
    for(double i = f_from; i < f_to; i += f_interval) {
        answer = function(i);
    }

    return answer;
}

int main()
{
    printf("<<Integration calculator>>\n");
    printf("Press q to terminate the program!\n");
    printf("Notice : This program merely parses the input.\n");
    printf("=================================================================\n");
    while(1) {
        printf("Please enter in the order of function, from, to, interval: ");

        char input[1000];
        if(fgets(input, 1000, stdin) == NULL || ((strlen(input) == 2) && input[0] == 'q'))
            break;
        input[strlen(input) - 1] = '\0';

        char *function = NULL, *from = NULL, *to = NULL, *interval = NULL;

        function = strtok(input, ",");
        from = strtok(NULL, ",");
        to = strtok(NULL, ",");
        interval = strtok(NULL, ",");

        printf("\n\nAfter strtok : %s %s %s %s\n", function, from, to, interval);

        if(function == NULL || from == NULL || to == NULL || interval == NULL) {
            printf("Input might be missing. -->invalid\n");
            continue;
        }

        printf("The answer is %f\n", integrate_function(tan, from, to, interval));


    }

    printf("Thanks for using this program. Bye~~\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

#define GET_DATA(str, size) fgets(str, (size), stdin)
#define PRINT_STR(str) for(int i=0;'\0'!=str[i];i++){printf("%c",str[i]);}printf("\n");

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define SUM_UP_ARRAY(array) int sum = 0; for(int i = 0; i < 100; i++){sum += array[i];}

int main()
{
    char input[100];
    GET_DATA(input, SIZE);
    PRINT_STR(input);

    printf("%d\n", MAX(100*2, 1000/10));

    int fuck[100] = {0};
    for(int i = 1; i <= 100; i++) {
        fuck[i - 1] = i;
    }

    SUM_UP_ARRAY(fuck);
    printf("%d\n", sum);

    return 0;
}
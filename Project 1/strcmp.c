#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], compare[100];
    fgets(input, 100, stdin);
    fgets(compare, 100, stdin);
    
    printf("strcmp %d\n", strcmp(input, compare));
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_increasing(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int cmp_decreasing(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int get_number(int input_num [], int length)
{
    int i, number = 0;
    for(i = 0; i < length; i++)
        number = number * 10 + input_num[i];
    return number;
}

int main()
{
    char input[20];
    fgets(input, 20, stdin);

    int i, len = 0, input_num[strlen(input) - 1];
    for(i = 0; i < (int)strlen(input) - 1; i++) {
        if(input[i] != ',') {
            input_num[len] = input[i] - '0';
            len++;
        }
    }

    qsort(input_num, len, sizeof(int), cmp_increasing);
    int increase = get_number(input_num, len);

    qsort(input_num, len, sizeof(int), cmp_decreasing);
    int decrease = get_number(input_num, len);

    printf("%d\n", decrease - increase);

    return 0;
}

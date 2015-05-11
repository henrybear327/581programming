#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

//clang-format-3.5 -i -style=LLVM main.c && astyle --style=linux main.c && clang -Wall -Wextra main.c -o main && ./main

int main()
{
    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--) {
        int input_count;
        scanf("%d", &input_count);

        int input[input_count];
        for (int i = 0; i < input_count; i++)
            scanf("%d", &input[i]);

        qsort(input, input_count, sizeof(int), cmp);

        int total = 0, index = 0;
        for (int i = input_count * 2 - 1; i > 0; i -= 2) {
            // printf("%d %d\n", i, input[i]);
            total += (i * input[index++]);
        }

        printf("%d\n", total);
    }

    return 0;
}
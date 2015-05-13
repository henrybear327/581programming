#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clang-format-3.5 -i -style=LLVM main.c && astyle --style=linux main.c &&
// clang -Wall -Wextra main.c -o main && ./main

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int data_count;
    while (scanf("%d", &data_count) != EOF && data_count) {

        int data[data_count];
        for (int i = 0; i < data_count; i++)
            scanf("%d", &data[i]);

        qsort(data, data_count, sizeof(int), cmp);

        int count = 0;
        for (int i = 0; i < data_count; i++) {
            for (int j = i + 1; j < data_count; j++) {
                for (int k = j + 1; k < data_count; k++) {
                    if (data[i] + data[j] > data[k])
                        count++;
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
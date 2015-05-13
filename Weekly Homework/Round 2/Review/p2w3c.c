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
    int test_case;
    scanf("%d", &test_case);
    while (test_case--) {
        int spy_count;
        scanf("%d", &spy_count);

        int spy[spy_count];
        for (int i = 1; i < spy_count; i++)
            scanf("%d", &spy[i]);

        int selection[spy_count], count = 0;
        memset(selection, 0, sizeof(selection));
        for (int i = spy_count - 1; i > 0; i--) {
            if (selection[spy[i]] == 0 && selection[i] == 0) {
                count++;
                selection[spy[i]] = 1;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
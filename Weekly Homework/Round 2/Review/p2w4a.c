#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clang-format-3.5 -i -style=LLVM main.c && astyle --style=linux main.c &&
// clang -Wall -Wextra main.c -o main && ./main

struct dimension {
    int length;
    int width;
};

int cmp(const void *a, const void *b)
{
    if (((struct dimension *)a)->width != ((struct dimension *)b)->width)
        return ((struct dimension *)b)->width - ((struct dimension *)a)->width;
    else
        return ((struct dimension *)a)->length - ((struct dimension *)b)->length;
}

int main()
{
    int test_case;
    scanf("%d", &test_case);
    while (test_case--) {
        int number_of_tiles;
        scanf("%d", &number_of_tiles);

        struct dimension tiles[number_of_tiles * 2];

        for (int i = 0; i < number_of_tiles; i++) {
            scanf("%d %d", &tiles[i].width, &tiles[i].length);
            tiles[i + number_of_tiles].width = tiles[i].length;
            tiles[i + number_of_tiles].length = tiles[i].width;
        }

        qsort(tiles, number_of_tiles * 2, sizeof(struct dimension), cmp);

        int sum = 0;
        for (int i = 0; i < number_of_tiles * 2;) {
            while (i + 1 < number_of_tiles * 2 &&
                   tiles[i].width == tiles[i + 1].width)
                i++;
            sum += tiles[i].length;
            i++;
        }
        printf("%d\n", sum);
    }

    return 0;
}
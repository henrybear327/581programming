#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
3
3
2 3
4 5
2 3
3
1 2
3 3
4 5
3
1 10
4 5
5 6

*/
typedef struct tileDimention {
    int length;
    int height;
} Dimention;

int cmp(const void *a, const void *b)
{
    return ((Dimention *)a) -> length - ((Dimention *)b) -> length;
}

#define DEBUG 0

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int tile_types;
            scanf("%d", &tile_types);

            Dimention input[tile_types * 2];
            for(int i = 0; i < tile_types * 2;) {
                scanf("%d %d", &input[i].length, &input[i].height);
                i++;

                input[i].length = input[i - 1].height;
                input[i].height = input[i - 1].length;
                i++;
            }

#if DEBUG
            for(int i = 0; i < tile_types * 2; i++) {
                printf("%d -> %d %d\n", i, input[i].length, input[i].height);
            }
#endif

            qsort(input, tile_types * 2, sizeof(Dimention), cmp);

#if DEBUG
            for(int i = 0; i < tile_types * 2; i++) {
                printf("%d -> %d %d\n", i, input[i].length, input[i].height);
            }
#endif

            int current = -1, ans_height = 0;
            for(int i = 0; i < tile_types * 2; i++) {
                if(input[i].length > current)
                    current = input[i].length;
                else
                    continue;

                int j = i, max = 0;
                while(input[j].length == current) {
                    if(input[j].height > max)
                        max = input[j].height;
                    j++;
                }
                ans_height += max;
            }

            printf("%d\n", ans_height);
        }
    }

    return 0;
}
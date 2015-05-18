#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

/*
3
2
0 1
2 3
3
0 20
10 30
40 50
5
10 30
0 20
0 10
40 50
10 20
1
5
0 1
2 3
0 1
2 3
1 2

*/

// clang-format-3.5 -i -style=LLVM  4.c && astyle --style=linux 4.c && clang
// -Wall -Wextra 4.c -o 4

typedef struct {
    int begin;
    int end;
} INTERVAL;

int cmp(const void *a, const void *b) //come on bro, can't even write a compare function??????
{
    if (((INTERVAL *)a)->begin == ((INTERVAL *)b)->begin)
        return ((INTERVAL *)a)->end - ((INTERVAL *)b)->end;
    else
        return ((INTERVAL *)a)->begin - ((INTERVAL *)b)->begin;
}

int main()
{
    int test_cases;
    while (scanf("%d", &test_cases) != EOF) {
        while (test_cases--) {
            int segments;
            scanf("%d", &segments);

            INTERVAL input[segments];
            for (int i = 0; i < segments; i++) {
                scanf("%d %d", &input[i].begin, &input[i].end);
                if (input[i].begin > input[i].end) {
                    int temp = input[i].begin;
                    input[i].begin = input[i].end;
                    input[i].end = temp;
                }
            }
            qsort(input, segments, sizeof(INTERVAL), cmp);

#if DEBUG
            for (int i = 0; i < segments; i++) {
                printf("%d %d\n", input[i].begin, input[i].end);
            }
#endif

            int beginning = 0, ending = 0, total = 0;
            for (int i = 0; i < segments; i++) {
                if (beginning <= input[i].begin && input[i].begin <= ending) {
                    if (input[i].end > ending) {
                        ending = input[i].end;
                    }
                } else {
                    total += ending - beginning;
                    beginning = input[i].begin;
                    ending = input[i].end;
                }
            }
            total += ending - beginning;

            printf("%d\n", total);
        }
    }

    return 0;
}
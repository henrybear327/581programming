#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2
4 7
1 5
2 6
3 8

15 1
1 5
1 3
1 10
2 14
2 4
3 8
4 3
5 2
5 11
6 2
6 6
8 9
8 6
8 7


*/

typedef struct {
    int leader;
    int conviviality;

    int picked;
    int ignored;
} ELEMENT;

#define DEBUG 0

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

int main()
{
    int test_cases;
    while (scanf("%d", &test_cases) != EOF) {
        getchar();
        while (test_cases--) {
            int count, i = 1;
            char input[100];
            ELEMENT data[1010];
            memset(data, 0, sizeof(data));

            fgets(input, 100, stdin);
            sscanf(input, "%d %d", &count, &data[i].conviviality);
            data[i].picked = data[i].conviviality;
            data[i].leader = -1;
            while (i++ <= count) {
                fgets(input, 100, stdin);
                sscanf(input, "%d %d", &data[i].leader, &data[i].conviviality);
                data[i].picked = data[i].conviviality;
            }

#if DEBUG
            for (i = 1; i <= count; i++) {
                printf("%d %d %d %d %d\n", i, data[i].leader, data[i].conviviality,
                       data[i].picked, data[i].ignored);
            }
            printf("\n\n");
#endif

            for (i = count; i > 1; i--) {
                data[data[i].leader].picked += data[i].ignored;
                data[data[i].leader].ignored += MAX(data[i].picked, data[i].ignored);
            }

#if DEBUG
            for (i = 1; i <= count; i++) {
                printf("%d %d %d %d %d\n", i, data[i].leader, data[i].conviviality,
                       data[i].picked, data[i].ignored);
            }
            printf("\n\n");
#endif

            printf("%d\n", MAX(data[1].picked, data[1].ignored));
        }
    }
    return 0;
}
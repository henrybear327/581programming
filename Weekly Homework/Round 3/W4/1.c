#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int cases;
    while (scanf("%d", &cases) != EOF && cases) {
        int book[2000] = { 0 }, min = 1000001, min_num = -1, min_left = -1,
                                min_right = -1;
        int original_cases = cases;
        while (cases--) {
            int temp;
            scanf("%d", &temp);
            if (book[temp] == 0) {
                book[temp] = cases;
            } else {
                if (MIN(book[temp] - cases, min) < min) {
                    min = MIN(book[temp] - cases, min);
                    min_left = original_cases - book[temp] - 1;
                    min_right = original_cases - cases - 1;
                    min_num = temp;
                }
                book[temp] = cases;
            }
        }

        if (min_num != -1)
            printf("(%d,%d):%d\n", min_left, min_right, min_num);
        else
            printf("No solution\n");
    }

    return 0;
}
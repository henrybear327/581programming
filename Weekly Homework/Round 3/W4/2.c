#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int cases;
    while (scanf("%d", &cases) != EOF && cases) {
        int book[2000] = { 0 }, max = -1, max_num = -1, max_left = -1,
                                max_right = -1;
        int original_cases = cases;
        while (cases--) {
            int temp;
            scanf("%d", &temp);
            if (book[temp] == 0) {
                book[temp] = cases;
            } else {
                if (MAX(book[temp] - cases, max) > max) {
                    max = MAX(book[temp] - cases, max);
                    max_left = original_cases - book[temp] - 1;
                    max_right = original_cases - cases - 1;
                    max_num = temp;
                }
            }
        }

        if (max_num != -1)
            printf("(%d,%d):%d\n", max_left, max_right, max_num);
        else
            printf("No solution\n");
    }

    return 0;
}
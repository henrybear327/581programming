#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int x, y;
            scanf("%d %d", &x, &y);
            int data[101][101];
            memset(data, 0, sizeof(data));

            int i, j;
            for(i = 0; i < x; i++) {
                for(j = 0; j < y; j++) {
                    scanf("%d", &data[i][j]);
                }
            }

            for(i = 0; i < x; i++) {
                for(j = 0; j < y; j++) {
                    if(data[i][j] == 0)
                        printf("_ ");
                    else {
                        if(i - 1 >= 0 && data[i - 1][j] == 0)/*left is 0*/
                            printf("0 ");
                        else if(i + 1 < x && data[i + 1][j] == 0)/*right is 0*/
                            printf("0 ");
                        else if(j - 1 >= 0 && data[i][j - 1] == 0)/*down is 0*/
                            printf("0 ");
                        else if(j + 1 < y && data[i][j + 1] == 0)/*top is 0*/
                            printf("0 ");
                        else
                            printf("_ ");
                    }
                }
                printf("\n");
            }
            if(test_cases != 0)
                printf("\n");
        }
    }

    return 0;
}
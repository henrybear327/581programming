#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int size;
    while (scanf("%d", &size) != EOF && size) {
        unsigned int board[size + 1][size + 1];
        memset(board, 0, sizeof(board));
        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= size; j++)
                scanf("%d", &board[i][j]);

        unsigned int dp[size + 1][size + 1];
        memset(dp, 0, sizeof(dp));

        // opt[i,j]=max{opt[i,j-1],opt[i-1,j]}+map[i,j],
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]) + board[i][j];
            }
        }

        printf("%u\n", dp[size][size]);
    }

    return 0;
}
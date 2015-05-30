#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 9999999
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int length, total_points, DP[50 + 2][50 + 2], cutting_points[52];

int cost(int left, int right)
{
    // two consecutive points -> return 0
    if (left == right - 1)
        return 0;
    // prev recorded result -> return directly from DP-array
    if (DP[left][right] != -1)
        return DP[left][right];

    // Calculate
    int min_cost = INF;
    for (int i = left + 1; i < right; i++) {
        min_cost = MIN(min_cost, (cutting_points[right] - cutting_points[left]) +
                       cost(left, i) + cost(i, right));
    }
    DP[left][right] = min_cost;
    return min_cost;
}

int main()
{
    while (scanf("%d %d", &length, &total_points) != EOF && length) {
        memset(DP, -1, sizeof(DP));

        for (int i = 1; i <= total_points; i++)
            scanf("%d", &cutting_points[i]);
        cutting_points[0] = 0;
        cutting_points[total_points + 1] = length;

        // total = length + minimum of (cost(0, left) + cost(left, length));
        int min_cost = INF;
        for (int i = 0; i < total_points; i++) {
            min_cost = MIN(min_cost, length + cost(0, i) + cost(i, total_points + 1));
        }

        printf("The minimum cutting is %d.\n", min_cost);
    }
    return 0;
}

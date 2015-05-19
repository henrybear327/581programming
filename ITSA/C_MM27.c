#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF) {
    	if(x > y) {
    		int temp = x;
    		x = y;
    		y = temp;
    	}
        int i, ans = 0;
        for (i = x; i <= y; i++)
            ans += i;
        printf("%d\n", ans);
    }
    return 0;
}

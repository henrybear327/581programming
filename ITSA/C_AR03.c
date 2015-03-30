#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cube_power(int);

int main()
{
    int data[6];
    while(scanf("%d%d%d%d%d%d", &data[0], &data[1], &data[2], &data[3], &data[4], &data[5]) != EOF) {
        int i, ans = 0;
        for(i = 0; i < 6; i++)
            ans += cube_power(data[i]);
        printf("%d\n", ans);

    }
    
    return 0;
}

int cube_power(int input)
{
    return input * input * input;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int data[6];
    while(scanf("%d%d%d%d%d%d", &data[0], &data[1], &data[2], &data[3], &data[4], &data[5]) != EOF) {
        int i;
        for(i = 5; i >= 0; i--)
            if(i != 0)
                printf("%d ", data[i]);
            else
                printf("%d\n", data[i]);
    }
    
    return 0;
}
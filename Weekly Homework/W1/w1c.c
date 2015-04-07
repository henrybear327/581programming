#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int data[100000 + 1];

int main()
{
    int p, q;
    while(scanf("%d %d", &p, &q) != EOF && q) {
        memset(data, -1, sizeof(data));
        if(p == q)
            printf("1\n");
        else {
            int count = 1;

            int remainder = p * 10 % q;
            while(data[remainder] == -1) {
                data[remainder] = count;
                count++;
                p = remainder;
                remainder = p * 10 % q;
            }
            printf("%d\n", count - data[remainder]);
        }
    }
    return 0;
}

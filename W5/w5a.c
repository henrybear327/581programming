#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        getchar();
        while(test_cases--) {
            int size;
            scanf("%d", &size);
            
            int data[size], max = 0, sum = 0;
            for(int i = 0; i < size; i++) {
                scanf("%d", &data[i]);
                sum += data[i];
                
                max = sum > max ? sum : max;
                
                if(sum < 0)
                    sum = 0;
                
            }
            
            
            if(sum >= 0)
                printf("%d\n", max);
            else 
                printf("0\n");
        }
    }

    return 0;
}
    #include <stdio.h>  
    #include <stdlib.h>  
    #include <string.h>  
    #include <math.h>  
      
    int main()  
    {  
        int b;  
        while (scanf("%d", &b) != EOF) {  
            if (b >= 31) {  
                printf("Value of more than 31\n");  
                continue;  
            }  
            int ans = 1 << b;  
            printf("%d\n", ans);  
        }  
        return 0;  
    }  
    #include <stdio.h>  
    #include <stdlib.h>  
    #include <string.h>  
    #include <math.h>  
      
    int main()  
    {  
        int a, b;  
        while (scanf("%d %d", &a, &b) != EOF) {  
            printf("%d\n", (a + b) * (a + b));  
        }  
        return 0;  
    }  
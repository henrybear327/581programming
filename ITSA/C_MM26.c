    #include <stdio.h>  
    #include <stdlib.h>  
    #include <string.h>  
    #include <math.h>  
      
    int main()  
    {  
        int input;  
        while (scanf("%d", &input) != EOF) {  
            int i;  
            for (i = 1; i <= input; i++)  
                printf("%d*%d=%d\n", i, i, i * i);  
        }  
        return 0;  
    }
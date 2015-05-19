    #include <stdio.h>  
    #include <stdlib.h>  
    #include <string.h>  
    #include <math.h>  
      
    int main()  
    {  
        int x, y;  
        while (scanf("%d %d", &x, &y) != EOF) {  
            if (0 <= x && x <= 100 && 0 <= y && y <= 100)  
                printf("inside\n");  
            else  
                printf("outside\n");  
        }  
        return 0;  
    }  
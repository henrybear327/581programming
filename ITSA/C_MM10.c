    #include <stdio.h>  
    #include <stdlib.h>  
    #include <string.h>  
    #include <math.h>  
      
    int main()  
    {  
        double input;  
        while (scanf("%lf", &input) != EOF) {  
            input = (input * 9 / 5) + 32;  
            printf("%.1lf\n", round(input * 10) / 10);  
        }  
        return 0;  
    }  
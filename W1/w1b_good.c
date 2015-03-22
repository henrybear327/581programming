#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,Q1,Q2,R1,R2;
    int i,min;

    scanf("%d",&n);
    while(n--) {
        scanf("%d %d %d %d",&Q1,&R1,&Q2,&R2);
        //printf("%d %d %d %d\n",Q1,R1,Q2,R2);

        if((Q1-R1)>(Q2-R2))
            min=Q2-R2;
        else
            min=Q1-R1;
        //printf("%d\n",min);

        for(i=1; i<=min; i++) {
            if((Q1-R1)%i==0&&(Q2-R2)%i==0) {
                if(i == 1)
                    printf("%d",i);
                else
                    printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
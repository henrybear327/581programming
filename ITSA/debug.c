#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int input;
    scanf("%d",&input);
    while(input--) {
        int N,M;
        scanf("%d %d",&N,&M);
        int i,j;
        int jobs[3000],data[10];
        memset(jobs,0,sizeof(jobs)); //use sizeof()
        memset(data,0,sizeof(data)); //use sizeof()
        for(i=0; i<N; i++) {
            scanf("%d",&jobs[i]);
        }

        int Min, Min_machine,k;
        Min= 2147483647; //Use a big number to start comparison with
        k=0;
        for(i=0; i<N; i++) {
            for(j=0; j<M; j++) {
                if(data[j]<Min) {
                    Min_machine=j; //record the smallest loading machine's index
                    Min = data[j];
                }
            }

            data[Min_machine]+=jobs[i];
            Min= 2147483647;
        }

        int Max;
        Max=0;
        for(i=0; i<M; i++) {
            if(data[i]>Max)
                Max=data[i];
        }
        printf("%d\n",Max);

    }
    return 0;
}

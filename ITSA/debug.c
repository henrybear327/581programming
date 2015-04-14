#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct x {
    long long int job;
    long long int deadline;
};

int cmp(const void*a,const void*b)
{
    return(((struct x*)a)->deadline-((struct x*)b)->deadline);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--) {
        int m,i;
        long long x[100]= {0};
        struct x data[100];
        scanf("%d",&m);
        for(i=0; i<m; i++)
            scanf("%lld",&data[i].job);
        for(i=0; i<m; i++)
            scanf("%lld",&data[i].deadline);
        qsort(data,m,sizeof(struct x),cmp);
        int temp=0;
        for(i=0; i<m; i++) {
            temp+=data[i].job;
            x[i]=temp;
        }
        int t = 0;
        for(i=0; i<m; i++) {
            if(x[i]>data[i].deadline) {
                t=1;
                break;
            }
        }
        if(t==1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

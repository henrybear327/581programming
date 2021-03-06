//#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 100

// make sure that there is '@'
int mycmp(char *p,char *q)
{
    char x[N]= {'0'},y[N]= {'0'};
    //int i,j;
    strncpy(x,p,strchr(p,'@')-p);
    strncpy(y,q,strchr(q,'@')-q);
    return strcmp(x,y);
}
int main()
{
    char a[10][N]= {"abc@gmail.com","acb@gmail.com","ab@gmail.com","a@xyz"};
    char line[N],c,*r;
    int i,j;
    printf("Before sorting:\n");
    for (i=0; i<4; i++) {
        printf("%s\n",a[i]);
    }
    printf("Showing how to get the user names:\n");
    for (i=0; i<4; i++) {
        if ((r=strchr(a[i],'@'))) printf("%d:",j=r-a[i]);
        strncpy(line,a[i],j);
        line[j]='\0';
        printf("%s\n",line);
    }
    qsort(a[0],4,N,mycmp);
    printf("After sorting:\n");
    for (i=0; i<4; i++) {
        printf("%s\n",a[i]);
    }
    return 0;
}

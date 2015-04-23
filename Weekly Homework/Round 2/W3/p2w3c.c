#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int spies;
            scanf("%d", &spies);

            int data[spies + 1];
            for(int i = 1; i < spies ; i++)
                scanf("%d", &data[i]);


            int ans = 0;
            while(1) {
                int i;
                for(i = spies - 1; i >= 1; i--) {
                    if(data[i] > 0)
                        break;
                }
                if(i == 0) {
                    int count = 0;
                    for(int j = spies - 1; j >= 1; j--) {
                        if(data[j] == 0)
                            count++;
                    }
                    if(count > 1)
                        ans++;
                    break;
                }

                int leader = data[i];

                data[leader] = -1;//the one above leaf
                ans++;
                //printf("ans %d\n", ans);

                data[i] = -2; //leaf


                for(int j = 1; j < spies; j++) {
                    if(data[j] == leader) {
                        data[j] = -2;
                    }
                }
                /*
                for(int j = 1; j < spies; j++)
                    printf("%d ", data[j]);
                printf("\n");
                */
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}
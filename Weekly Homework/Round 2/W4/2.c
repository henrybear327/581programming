#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define debug 0

typedef struct timeAvailable {
    int start;
    int end;
    int length;
} Availability;

int cmp(const void *a, const void *b)
{
    if( ((Availability *)a) -> start != ((Availability *)b) -> start)
        return ((Availability *)a) -> start - ((Availability *)b) -> start;
    else
        return ((Availability *)a) -> length - ((Availability *)b) -> length;
}

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        getchar(); //git rid of \n
        getchar(); //get rid of first blank line
        while(test_cases--) {
            char input[100];
            int i = 0;
            Availability data[50];
            while(1) {
                if(fgets(input, 100, stdin) == NULL || input[0] == '\n')
                    break;

                sscanf(input, "%d %d", &data[i].start, &data[i].end);
                if(data[i].start > data[i].end) {
                    int temp = data[i].start;
                    data[i].start = data[i].end;
                    data[i].end = temp;
                }

                data[i].length = data[i].end - data[i].start;

                i++;
            }

#if debug
            for(int j = 0; j < i; j++)
                printf("%d %d %d\n", data[j].start, data[j].end, data[j].length);
#endif

            qsort(data, i, sizeof(Availability), cmp);

#if debug
            for(int j = 0; j < i; j++)
                printf("%d %d %d\n", data[j].start, data[j].end, data[j].length);
#endif

            //printf("Hello!\n");

            int start = 0, end = 0, j,count = 1;
            for(j = 0; data[j].start == 0; j++);
            end = data[j - 1].end;

            int max_end = 0, max_end_k = 0;
            for(int k = j; k < i;) {
                max_end = 0;
                while(data[k].start > start && data[k].start <= end + 1) {
                    if(data[k].end == 199) {
                        count++;
                        goto end;
                    } else if(data[k].end > max_end) {
                        max_end = data[k].end;
                        max_end_k = k;
                    }
                    k++;
                }

                start = data[max_end_k].start;
                end = data[max_end_k].end;
                count++;
            }

end:
            printf("%d\n", count);

        }

        return 0;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define debug 0
#define DEBUG 0

void q_sort(void *mem_start, size_t total_member, size_t member_size,
            int (*cmp)(const void *, const void *));

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

            q_sort(data, i, sizeof(Availability), cmp);

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

void q_sort(void *mem_start, size_t total_member, size_t member_size,
            int (*cmp)(const void *, const void *))
{
    //zd for printing size_t
    //printf("arguments : %p, %zd, %zd, %p\n", mem_start, total_member, member_size, cmp);
    if(total_member > 1) {
        void *pivot = mem_start;
        void *to_compare = mem_start + (total_member - 1) * member_size;

#if DEBUG
        printf("Init pivot = %p, to_compare = %p\n\n", pivot, to_compare);
        getchar();
#endif

        while(pivot != to_compare) {
            if((cmp(pivot, to_compare) > 0 && to_compare > pivot) || (cmp(to_compare, pivot) > 0 && pivot > to_compare)) { //pivot > to_compare
                //pivot <-> to_compare
                void *temp = malloc(member_size);
                memcpy(temp, pivot, member_size);
                memcpy(pivot, to_compare, member_size);
                memcpy(to_compare, temp, member_size);
                free(temp);

                temp = pivot;
                pivot = to_compare;
                to_compare = temp;

                if(pivot < to_compare)
                    to_compare -= member_size;
                else
                    to_compare += member_size;
            } else {
                if(pivot < to_compare)
                    to_compare -= member_size;
                else
                    to_compare += member_size;
            }
        }

#if DEBUG
        printf("After : pivot = %p, to_compare = %p\n", pivot, to_compare);
#endif
        //printf("First Call\n");
        q_sort(mem_start, ((pivot - mem_start) / member_size), member_size, cmp);

        //printf("Second Call\n");
        //printf("%lu\n", (to_compare - mem_start) / member_size);
        q_sort(pivot + member_size, (total_member - ((to_compare - mem_start) / member_size + 1)), member_size, cmp);
    } else {
        //printf("member_size <= 1\n");
        //only one or less element, no need to sort
        return;
    }
}

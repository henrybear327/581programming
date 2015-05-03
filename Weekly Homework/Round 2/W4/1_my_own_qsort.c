#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tileDimention {
    int length;
    int height;
} Dimention;

#define DEBUG 0
void q_sort(void *mem_start, size_t total_member, size_t member_size,
            int (*cmp)(const void *, const void *));

int cmp(const void *a, const void *b)
{
    return ((Dimention *)a) -> length - ((Dimention *)b) -> length;
}

int main()
{
    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int tile_types;
            scanf("%d", &tile_types);

            Dimention input[tile_types * 2];
            for(int i = 0; i < tile_types * 2;) {
                scanf("%d %d", &input[i].length, &input[i].height);
                i++;

                input[i].length = input[i - 1].height;
                input[i].height = input[i - 1].length;
                i++;
            }

#if DEBUG
            for(int i = 0; i < tile_types * 2; i++) {
                printf("%d -> %d %d\n", i, input[i].length, input[i].height);
            }
#endif

            qsort(input, tile_types * 2, sizeof(Dimention), cmp);

#if DEBUG
            for(int i = 0; i < tile_types * 2; i++) {
                printf("%d -> %d %d\n", i, input[i].length, input[i].height);
            }
#endif

            int current = -1, ans_height = 0;
            for(int i = 0; i < tile_types * 2; i++) {
                if(input[i].length > current)
                    current = input[i].length;
                else
                    continue;

                int j = i, max = 0;
                while(input[j].length == current) {
                    if(input[j].height > max)
                        max = input[j].height;
                    j++;
                }
                ans_height += max;
            }

            printf("%d\n", ans_height);
        }
    }

    return 0;
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
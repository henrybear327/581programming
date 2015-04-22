#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void push(int);
void pop(void);
int top(void);
int is_empty(void);

#define DEBUG 0

int next_empty_index = 1, capacity = 2, *data = NULL;

int main()
{

    int test_case;
    while(scanf("%d", &test_case) != EOF) {
        while(test_case--) {
            int N, M;
            scanf("%d %d", &N, &M);

            capacity = 2;

            data = (int *)malloc(sizeof(int) * capacity);
            if(data == NULL) {
                printf("Malloc failed.\n");
                return 0;
            }

            for(int i = 0; i < M; i++)
                push(0);

            while(N--) {
                int job;
                scanf("%d", &job);
                int temp = top();

                if(DEBUG == 1) {
                    printf("top %d\n", temp);
                }

                pop();
                temp += job;
                push(temp);

                if(DEBUG == 1) {
                    printf("push temp %d\n\n\n", temp);
                }
            }
            //printf("%d\n", next_empty_index);

            int answer;
            while (is_empty() == false) {
                answer = top();
                pop();
            }

            free(data);

            printf("%d\n", answer);
        }
    }
    return 0;
}

void push(int value)
{
    //printf("Push\n");

    if(capacity - 1 <= next_empty_index) {
        //printf("Reallocating...\n");
        capacity = (capacity - 1) * 2 + 1;

        int *temp = (int *)malloc(sizeof(int) * capacity);
        if(temp == NULL) {
            printf("Malloc failed.\n");
            exit(0);
        }

        memcpy(temp, data, sizeof(int) * (next_empty_index + 1));
        free(data);
        data = temp;

        /*
        printf("Check memcpy\n");
        for(int i = 1; i < next_empty_index; i++)
            printf("i = %d, %d\n", i, data[i]);
        printf("\n");
        */


        //printf("capacity %d\n", capacity);
    }

    data[next_empty_index] = value;
    //printf("data[next_empty_index] = %d\n", data[next_empty_index]);
    int index = next_empty_index;
    next_empty_index++;

    while(index != 1 && data[index] < data[index / 2]) {
        int temp = data[index];
        data[index] = data[index / 2];
        data[index / 2] = temp;
        index /= 2;
    }

    if(DEBUG == 1) {
        printf("Result of pushing...\n");
        for(int i = 1; i < next_empty_index; i++)
            printf("i = %d, %d\n", i, data[i]);
        printf("\n");
    }
}
void pop(void)
{
    //printf("Pop\n");

    if(next_empty_index != 1) {
        next_empty_index--;
        data[1] = data[next_empty_index];
        data[next_empty_index] = 0;
    } else {
        return;
    }

    int parent = 1, child = 2;
    while(child < next_empty_index) {
        if(child + 1 < next_empty_index && data[child] > data[child + 1])
            child++;
        if(data[parent] > data[child]) {
            int temp = data[child];
            data[child] = data[parent];
            data[parent] = temp;
        } else {
            break;
        }

        parent = child;
        child *= 2; //?

    }

    if(DEBUG == 1) {
        printf("Result of poping...\n");
        for(int i = 1; i < next_empty_index; i++)
            printf("i = %d, %d\n", i, data[i]);
        printf("\n");
    }

}
int top(void)
{
    //printf("Top\n");
    return data[1];
}
int is_empty(void)
{
    //printf("is_empty\n");
    if(next_empty_index == 1)
        return true;
    else
        return false;
}

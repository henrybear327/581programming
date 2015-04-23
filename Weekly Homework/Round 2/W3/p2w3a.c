#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEBUG 0

void push(int);
void pop(void);
int top(void);
int is_empty(void);

int next_empty_index = 1, capacity = 2, *data = NULL;

int main()
{
    data = (int *)malloc(sizeof(int) * capacity);
    if(data == NULL) {
        printf("Malloc failed.\n");
        return 0;
    }

    int test_cases;
    while(scanf("%d", &test_cases) != EOF) {
        while(test_cases--) {
            int jobs, deadline;
            scanf("%d %d", &jobs, &deadline);

            int data[jobs];
            int i;
            for(i = 0; i < jobs; i++) {
                scanf("%d", &data[i]);
                if(data[i] > deadline) {
                    printf("-1\n");
                    break;
                }
            }
            if(i != jobs)
                continue;

            int machines = 1, max = 0, min = 0, flag = false, last_check = false;
            while(1) {
                //use binary search concept

                while(is_empty() == false)
                    pop();
                for(i = 0; i < machines; i++)
                    push(0);
                //printf("machines %d\n", machines);

                for(i = 0; i < jobs; i++) {
                    int least_load = top();
                    //printf("i = %d, top = %d\n", i, top());
                    pop();

                    if(least_load + data[i] > deadline) {
                        break;
                    }

                    push(least_load + data[i]);
                    //printf("i = %d, least_load + data[i] = %d\n", i, least_load + data[i]);
                }

                if(i != jobs && flag == false) {
                    machines *= 2;
                    continue;
                }

                if(flag == false) {
                    //printf("machines %d, Change to true\n", machines);
                    flag = true;
                    max = machines;
                    min = machines / 2;
                    machines = (max + min) / 2;
                    continue;
                }

                if(i != jobs && flag == true) {
                    //printf("machines %d, min\n", machines);
                    if(last_check == true)
                        machines++;

                    min = machines;
                    machines = (max + min) / 2;
                } else if(i == jobs && flag == true) {
                    //printf("machines %d, max\n", machines);

                    max = machines;
                    machines = (max + min) / 2;
                }
                //printf("min %d , max %d\n",min, max);

                if(min + 1 == max) {
                    if(last_check == false) {
                        last_check = true;
                        machines = min;
                        continue;
                    } else if(last_check == true) {
                        printf("%d\n", machines);
                    }

                } else if(max == min) {
                    printf("%d\n", machines);
                    break;
                }
            }
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
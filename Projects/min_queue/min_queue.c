#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void push(int);
void pop(void);
int top(void);
int is_empty(void);

int last_empty_position = 1, capacity = 2, *data = NULL;

#define DEBUG 1

int main()
{
    data = (int *)malloc(sizeof(int) * capacity);
    if(data == NULL) {
        printf("Malloc failed.\n");
        return 0;
    }

    int operation, value;
    while(scanf("%d", &operation) != EOF) {
        switch(operation) {
        case 0:
            printf("Program exits.\n");
            return 0;
        case 1:
            printf("Push value?\n");
            scanf("%d", &value);
            push(value);

            printf("Result of pushing...\n");
            for(int i = 1; i < last_empty_position; i++)
                printf("i = %d, %d\n", i, data[i]);
            printf("\n");
            break;
        case 2:
            printf("Pop\n");
            pop();
            break;
        case 3:
            printf("Top is %d\n", top());
            break;
        case 4:
            printf("Is empty? %d\n", is_empty());
            break;
        default:
            printf("Wrong input.\n");
            break;
        }
    }

    return 0;
}

void push(int value)
{
    //printf("Push\n");

    if(capacity - 1 <= last_empty_position) {
        //printf("Reallocating...\n");
        capacity = (capacity - 1) * 2 + 1;

        int *temp = (int *)malloc(sizeof(int) * capacity);
        if(temp == NULL) {
            printf("Malloc failed.\n");
            exit(0);
        }

        memcpy(temp, data, sizeof(int) * (last_empty_position + 1));
        free(data);
        data = temp;

        /*
        printf("Check memcpy\n");
        for(int i = 1; i < last_empty_position; i++)
            printf("i = %d, %d\n", i, data[i]);
        printf("\n");
        */


        //printf("capacity %d\n", capacity);
    }

    data[last_empty_position] = value;
    //printf("data[last_empty_position] = %d\n", data[last_empty_position]);
    int index = last_empty_position;
    last_empty_position++;

    while(index != 1 && (data[index] < data[index / 2] || data[index] < data[index / 2 + 1])) {
        if(data[index] < data[index / 2]) {
            int temp = data[index];
            data[index] = data[index / 2];
            data[index / 2] = temp;
            index /= 2;
        } else if((data[index] < data[index / 2 + 1]) && (index / 2 + 1 < last_empty_position)) {
            int temp = data[index];
            data[index] = data[index / 2 + 1];
            data[index / 2 + 1] = temp;
            index = index / 2 + 1;
        } else {
            break;
        }
    }

    if(DEBUG == 1) {
        printf("Result of pushing...\n");
        for(int i = 1; i < last_empty_position; i++)
            printf("i = %d, %d\n", i, data[i]);
        printf("\n");
    }
}
void pop(void)
{
    //printf("Pop\n");

    if(last_empty_position != 1) {
        last_empty_position--;
        data[1] = data[last_empty_position];
        data[last_empty_position] = 0;
    }

    int index = 1;
    while(index * 2 < last_empty_position && (data[index] > data[index * 2] || data[index] > data[index * 2 + 1])) {
        if(data[index] > data[index * 2]) {
            int temp = data[index];
            data[index] = data[index * 2];
            data[index * 2] = temp;
            index *= 2;
        } else if((data[index] > data[index * 2 + 1]) && (index * 2 + 1 < last_empty_position)) {
            int temp = data[index];
            data[index] = data[index * 2 + 1];
            data[index * 2 + 1] = temp;
            index = index * 2 + 1;
        } else {
            break;
        }
    }

    if(DEBUG == 1) {
        printf("Result of poping...\n");
        for(int i = 1; i < last_empty_position; i++)
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
    if(last_empty_position == 1)
        return true;
    else
        return false;
}

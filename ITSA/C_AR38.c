#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int size;
    scanf("%d", &size);
    size++; //making the data stored and used in 1 ~ size format

    int input[size];

    for(int i = 1; i < size; i++)
        scanf("%d", &input[i]);

    int index = 1, answer[size];
    memset(answer, -1, sizeof(answer));

    while(1) {
        //deal with 0 first
        for(int i = 1; i < size; i++)
            if(input[i] == 0)
                answer[index++] = i;

        for(int i = 1; i < size; i++) {
            if(input[i] == 0)
                continue;

            int j, count = input[i];
            for(j = 1; j < size && count; j++) {
                if(answer[j] > i ||  answer[j] == -1)
                    count--;
            }

            while(j < size) {
                if(answer[j] == -1) {
                    answer[j] = i;
                    break;
                } else if(answer[j] < i) {
                    j++;
                    continue;
                } else if(answer[j] > i) { //right shift
                    int shift[size];
                    memset(shift, -1, sizeof(shift));
                    for(int k = j; k < size - 1; k++) {
                        if(answer[k] != -1)
                            shift[k + 1] = answer[k];
                        else
                            break;
                    }
                    for(int k = j + 1; k < size - 1; k++) {
                        if(shift[k] != -1)
                            answer[k] = shift[k];
                        else
                            break;
                    }
                    answer[j] = i;
                }
                break;
            }

            /*printf("i = %d, j = %d\n", i, j);
            for(int i = 1; i < size; i++) {
                if(i != size - 1)
                    printf("%d ", answer[i]);
                else
                    printf("%d\n", answer[i]);
            }*/
        }

        break;
    }

    for(int i = 1; i < size; i++) {
        if(i != size - 1)
            printf("%d ", answer[i]);
        else
            printf("%d\n", answer[i]);
    }

    return 0;
}
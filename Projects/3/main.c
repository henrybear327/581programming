/*
The memory of array should be obtained by malloc with only one cell initially.
Double size whenever insertion-on-full
Alloc double size, Copy the current data, and then Insert the new data

Each record has three fields:
char name [16]
int age
enum {female, male} sex

The input is like “Peter Wang”, 35, female
Each line of the input is a record to be inserted

Output:
After insertion insert record,  name=XXX,age=NN,sex=male;
When insertion-to-full: output message “queue/stack full, allocate double size NN”
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char name[20];
    int age;
    enum {female, male} sex;
} DATA;

int parsing(DATA **, int, char *);

char *sex_str[2] = {"female", "male"};

int main()
{
    int capacity = 1, current_struct = 0;
    DATA *input = (DATA *)malloc(sizeof(DATA) * capacity);
    char input_str[1000];

    while(fgets(input_str, 1000, stdin) != NULL) {
        if(current_struct + 1 > capacity) {
            printf("Storage insufficient. Expanding from %d to %d\n", capacity, capacity * 2);
            capacity *= 2;

            DATA *temp = (DATA *)malloc(sizeof(DATA) * capacity);
            if(temp == NULL) {
                printf("Malloc failed. Program ends now.\n");
                return 0;
            }
            memcpy(temp, input, sizeof(DATA) * (current_struct + 1));
            free(input);
            input = temp;
            printf("Malloc completed.\n");
        }
        if(parsing(&input, current_struct, input_str) == false)
            printf(" --> Illigal input.\n");
        else
            printf(" --> Input accepted.\n");

        current_struct++;
    }

    for(int i = 0; i < current_struct; i++)
        printf("%s\n", (input + i) -> name);

    return 0;
}

int parsing(DATA **string, int current_struct, char *input_str)
{
    /*
    The input is like “Peter Wang”, 35, female
    */

    //parse for name

    //Check for quotation mark
    printf("%s", input_str);
    if(input_str[0] != '"') {
        printf("Input not starting with a \".");
        return false;
    }
    int length = 1;
    char name_string[20] = {'\0'};
    while(1) {
        if(isalpha(input_str[length]) || input_str[length] == ' ') { //normal
            name_string[length - 1] = input_str[length];
            length++;
            continue;
        } else {
            if(input_str[length] == '"') { //end string
                break;
            } else {
                printf("Illigal character(s) detected.");
                return false;
            }
        }
    }
    length--;

    if(length == 0) {
        printf("No name is entered.");
        return false;
    } else if(length > 16) {
        printf("The name is too long. (More than 16 characters)");
        return false;
    }

    printf("%s\n", name_string);
    strcpy((*string + current_struct) -> name, name_string);
    printf("%s\n", (*string + current_struct) -> name);

    //All is good
    printf("The input is checked.");
    return true;
}
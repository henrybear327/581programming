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
        //check and allocate space for storing info
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

        if(parsing(&input, current_struct, input_str) == false || strlen(input_str) < 5) { // 5 because "",,\n
            printf(" --> Illigal input.\n");
        } else {
            printf(" --> Input accepted.\n");
            current_struct++;
        }
    }

    for(int i = 0; i < current_struct; i++) //current_struct is the correct number to use
        printf("%s\n", (input + i) -> name);

    return 0;
}

int parsing(DATA **string, int current_struct, char *input_str)
{
    /*
    The input is like “Peter Wang”, 35, female
    */

    //check for existence
    char *name = strtok(input_str, ","), *age = strtok(NULL, ","), *gender = strtok(NULL, ",");

    if((name == NULL) || (age == NULL) || (gender == NULL)) {
        printf("Missing name, age, or gender in the input.");
        return false;
    } else if(strlen(name) == 0 || strlen(age) == 0 || strlen(gender) == 0) {
        printf("Missing name, age, or gender in the input.");
        return false;
    }

    //check name
    if(name[0] != '"' || name[strlen(name)] != '"') {
        printf("The name in the input isn't surrounded by quotation mark");
        return false;
    }

    int name_length = 0, space = 0;
    while(name_length <= 16 && name_length != (int)strlen(name) - 1) {
        if(isalpha(input_str[name_length + 1])) {
            name_length++;
        } else if(input_str[name_length + 1] == ' ') {
            space++;
            name_length++;
        } else {
            printf("Illigal character detected in name.");
            return false;
        }
    }

    if(space == name_length) {
        printf("Only spaces in name.");
        return false;
    }


    //Pass all tests
    printf("The input is checked.");
    return true;
}
/*
The memory of array should be obtained by malloc with only one cell initially.
Double size whenever insertion-on-full
Alloc double size, Copy the current data, and then Insert the new data

Each record has three fields:
char name [16]
int age
enum {female, male} sex

The input is like ¡§Peter Wang¡¨, 35, female
Each line of the input is a record to be inserted

Output:
After insertion insert record,  name=XXX,age=NN,sex=male;
When insertion-to-full: output message ¡§queue/stack full, allocate double size NN¡¨
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

int main()
{
    int capacity = 1, current_struct = 0, input_count = 1;
    DATA *input = (DATA *)malloc(sizeof(DATA) * capacity);
    char input_str[1000];

    while(fgets(input_str, 1000, stdin) != NULL) {
        printf("Input %d : %s", input_count, input_str);

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
            printf(" --> Illigal input\n\n");
            input_count++;
        } else {
            input_count++;
            printf(" --> Input accepted\n");
            char *valid_gender[2] = {"female", "male"};
            printf("%s, %d, %d(%s)\n\n\n", (input + current_struct) -> name, (input + current_struct) -> age, \
                   (input + current_struct) -> sex, valid_gender[(input + current_struct) -> sex]);
            current_struct++;
        }
    }

    printf("============================================\n");
    if(current_struct != 0) {
        printf("The correct inputs are listed as follow...\n\n");
        char *valid_gender[2] = {"female", "male"};
        for(int i = 0; i < current_struct; i++) { //current_struct is the correct number to use
            printf("%d --> %s, %d, %d(%s)\n", i + 1, (input + i) -> name, (input + i) -> age, \
                   (input + i) -> sex, valid_gender[(input + i) -> sex]);
        }
    } else {
        printf("There is no correct input at all.\n");
    }

    return 0;
}

int parsing(DATA **string, int current_struct, char *input_str)
{
    /*
    The input is like ¡§Peter Wang¡¨, 35, female
    */

    //check for existence
    int comma_count = 0;
    for(int i = 0; i < (int)strlen(input_str); i++)
        if(input_str[i] == ',')
            comma_count++;
    if(comma_count != 2) {
        printf("The number of comma isn't correct.");
        return false;
    }

    char *name = strtok(input_str, ","), *age = strtok(NULL, ","), *gender = strtok(NULL, ",");

    if((name == NULL) || (age == NULL) || (gender == NULL)) {
        printf("Missing comma in the input");
        return false;
    } else if(strlen(name) <= 2 || strlen(age) == 0 || strlen(gender) == 0) {
        printf("Missing name, age, or gender in the input.");
        return false;
    }

    //check name
    if(name[0] != '"' || name[strlen(name) - 1] != '"') {
        printf("The name in the input isn't surrounded by quotation mark");
        return false;
    }

    int name_length = 1, space_count = 0;
    while(name_length != (int)strlen(name) - 1) {
        if(name_length > 16) {
            printf("The name is longer than 16 characters in total.");
            return false;
        } else if(isalpha(name[name_length]) != false) {
            name_length++;
        } else if(name[name_length] == ' ') {
            space_count++;
            name_length++;
        } else if(name[name_length] == '"') {
            printf("More than two quotation marks are entered.(position : %d)", name_length);
            return false;
        } else {
            printf("Illigal character detected in name.(position : %d)", name_length);
            return false;
        }
    }
    name_length--;

    if(space_count == name_length) {
        printf("Only spaces in name.");
        return false;
    }

    strcpy((*string + current_struct) -> name, name);

    //check age
    space_count = 0;
    for(int i = 0; i < (int)strlen(age); i++) {
        if(age[i] == ' ') {
            space_count++;
        } else if(isdigit(age[i]) == false) {
            printf("The age entered is not a number.");
            return false;
        }
    }

    if(space_count == (int)strlen(age)) {
        printf("Only spaces in age.");
        return false;
    }

    ((*string + current_struct) -> age) = atoi(age);

    //check gender
    char gender_str[100] = {'\0'};
    int index = 0;
    for(int i = 0; i < (int)strlen(gender) - 1; i++) {
        if(isalpha(gender[i]) == false && gender[i] != ' ') {
            printf("Illigal character detected in gender.(position : %d)", i);
            return false;
        }
        if('A' <= gender[i] && gender[i] <= 'Z')
            gender_str[index++] = gender[i] - 'A' + 'a';
        else if('a' <= gender[i] && gender[i] <= 'z')
            gender_str[index++] = gender[i];
    }

    char *valid_gender[] = {"female", "male"};
    if((strcmp(gender_str, valid_gender[0]) != 0) && (strcmp(gender_str, valid_gender[1]) != 0)) {
        printf("Wrong gender info is provided. Only male/female is accepted.(Mixed case is accepted)");
        return false;
    }

    if(strcmp(gender_str, valid_gender[0]) == 0)
        ((*string + current_struct) -> sex) = female;
    else
        ((*string + current_struct) -> sex) = male;

    //Pass all tests
    printf("The input is checked.");
    return true;
}

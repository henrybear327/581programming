/*
Input: a set of strings
Goal:
    - recognize the strings which are valid email address
    - sort them by (upper and lower cases are regarded as the same.)
        (i) username
        (ii) domain name + username

Input format:
3
bangye.wu@gmail.com
bang@tt@tt
bangye@abc.edf.edg

Basic requirement: at least 5 string functions, correct recognition
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool valid_input(char *);

struct email {
    char *username;
    char *domain_name;
};

int main()
{
    //Prompt the user to input the number of cases and check for validity
    int cases;
    while(1) {
        printf("Please enter the quantity of email addresses the input will consist: ");

        char input_case[100];
        fgets(input_case, 100, stdin);
        if((cases = atoi(input_case)) == 0) //atoi will return 0 if the input is invalid
            printf("Please enter a number that consists only 0~9.\n");
        else
            break;
    }

    //Prompt the user to input some email addresses
    struct email data[cases];

    printf("Please enter %d email address(es). The program will check validity and sort them.\n", cases);
    int count = 0;
    while(count < cases) {
        char input[200] = {'\0'};
        fgets(input, 200, stdin);
        input[strlen(input) - 1] = '\0';

        if(valid_input(input) == true) {
            //breakdown the input into username and domain name
            printf("Input no.%d accepted\n", count + 1);

            data[count].username = strtok(input, "@");
            data[count].domain_name = strtok(NULL, "\0");

            printf("The input %d is %s@%s\n\n", count + 1, data[count].username, data[count].domain_name);
        } else {
            printf("The input %s is invalid.\n", input);
        }

        count++;
    }

    //print out the result sorted by username

    //print out the result sorted by domain name

    return 0;
}

bool valid_input(char *input)
{
    /*
    Make sure that (in order)
    1. There is only one @
    2. There are always legal characters before and after @
    3. There is at least one . in both username and domain name
    4. There are always legal characters before and after .
    */

    struct email test;

    //Part 1
    int count = 0;
    char *ptr = strchr(input, '@');
    while(ptr != NULL) {
        count++;
        //printf("ptr = %s\n", ptr);
        //printf("%ld\n", ptr - input);
        if(count > 1)
            return false; //more than one @

        ptr = strchr(ptr + 1, '@');
    }
    if(count == 0)
        return false; // no @

    //Disintegrate
    char *temp = (char *)malloc(strlen(input) + 2);
    strncpy(temp, input, strlen(input) + 2);
    test.username = strtok(temp, "@");
    if(test.username[0] == '@')
        return false; //nothing before @
    if((test.domain_name = strtok(NULL, "\0")) == NULL)
        return false; //nothing behind @

    //Part 2


    return true;
}
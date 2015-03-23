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
    printf("\n");

    //Prompt the user to input some email addresses
    struct email data[cases];

    printf("Please enter %d email address(es). The program will check validity and sort them.\n\n", cases);
    int count = 0, valid_count = 0;
    while(count < cases) {
        count++;
        valid_count++;

        char input[200] = {'\0'};
        fgets(input, 200, stdin);
        input[strlen(input) - 1] = '\0';

        //check inputted email address
        if(valid_input(input) == true) {
            //breakdown the input into username and domain name
            printf("\nInput no.%d accepted\n", valid_count);

            data[count].username = strtok(input, "@");
            data[count].domain_name = strtok(NULL, "\0");

            printf("The input %d is %s@%s (%d input(s) remaining)\n\n", valid_count, data[count].username, data[count].domain_name, cases - count);
        } else {
            valid_count--;
            printf(" (%d input(s) remaining)\n\n", cases - count);
        }
    }
    printf("All inputs have been checked. There are %d valid input put of %d.\n", valid_count, cases);

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
        if(count > 1) {
            printf("Input invalid -> more than one @ is found in the email address.");
            return false; //more than one @
        }
        ptr = strchr(ptr + 1, '@');
    }
    if(count == 0) {
        printf("Input invalid -> missing @ in the email address.");
        return false; // no @
    }

    //Disintegrate, Part 2
    char *temp = (char *)malloc(strlen(input) + 2);
    strncpy(temp, input, strlen(input) + 2);
    test.username = strtok(temp, "@");
    if(test.username == NULL) { //strtok will start scanning from the first char that's not delimiter
        printf("Input invalid -> missing characters before @ in the email address.");
        return false; //nothing before @
    }
    if((test.domain_name = strtok(NULL, "\0")) == NULL) {
        printf("Input invalid -> missing characters after @ in the email address.");
        return false; //nothing behind @
    }

    //Part 2 (check for legal characters), Part 3

    int dot_present = false;
    for(int i = 0; i < strlen(test.username); i++) {
        if(isalnum(test.username[i]) == 0 && test.username[i] != '.') { //isalnum return 0 for false
            printf("Input invalid -> illegal character in username.");
            return false;
        }
        if(test.username[i] == '.')
            dot_present = true;
    }
    if(dot_present == false) {
        printf("Input invalid -> missing . in username.");
        return false;
    }

    dot_present = false;
    for(int i = 0; i < strlen(test.domain_name); i++) {
        if(isalnum(test.domain_name[i]) == 0 && test.domain_name[i] != '.') { //isalnum return 0 for false
            printf("Input invalid -> illegal character in the domain name.");
            return false;
        }
        if(test.domain_name[i] == '.')
            dot_present = true;
    }
    if(dot_present == false) {
        printf("Input invalid -> missing . in domain name.");
        return false;
    }

    //Part 4 .@.

    bool consecutive_dots = false;

    if(test.username[0] == '.') {
        printf("Input invalid -> missing characters before .");
        return false;
    } else if(test.username[strlen(test.username) - 1] == '.') {
        printf("Input invalid -> missing characters after .");
        return false;
    }

    for(int i = 0; i < strlen(test.username); i++) {
        if(test.username[i] == '.' && consecutive_dots == false) {
            consecutive_dots = true;
        } else if(test.username[i] == '.' && consecutive_dots == true) {
            printf("Input invalid -> missing characters in between .");
            return false;
        } else {
            consecutive_dots = false;
        }
    }
    if(consecutive_dots == true) {
        printf("Input invalid -> missing characters after .");
        return false;
    }

    consecutive_dots = false;

    if(test.domain_name[0] == '.') {
        printf("Input invalid -> missing characters before .");
        return false;
    } else if(test.domain_name[strlen(test.domain_name) - 1] == '.') {
        printf("Input invalid -> missing characters after .");
        return false;
    }

    for(int i = 0; i < strlen(test.domain_name); i++) {
        if(test.domain_name[i] == '.' && consecutive_dots == false) {
            consecutive_dots = true;
        } else if(test.domain_name[i] == '.' && consecutive_dots == true) {
            printf("Input invalid -> missing characters in between .");
            return false;
        } else {
            consecutive_dots = false;
        }
    }
    if(consecutive_dots == true) {
        printf("Input invalid -> missing characters after .");
        return false;
    }

    return true;
}
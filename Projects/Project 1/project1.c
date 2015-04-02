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

/*
Functions used: strlen, strtok, strcpy, strchr, strncpy
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

int compare_username(const void *a, const void *b)
{
    struct email *input1 = (struct email *)a, *input2 = (struct email *)b;
    char lower1[200], lower2[200], lower3[200], lower4[200];
    //struct email lower1 = *input1, lower2 = *input2; wrong because struct email is declared using char *
    memcpy(lower1, input1 -> username, sizeof(char) * (strlen(input1 -> username) + 1));
    for(int i = 0; i < strlen(lower1); i++)
        lower1[i] = tolower(input1 -> username[i]);
    memcpy(lower2, input2 -> username, sizeof(char) * (strlen(input2 -> username) + 1));
    for(int i = 0; i < strlen(lower2); i++)
        lower2[i] = tolower(input2 -> username[i]);
    memcpy(lower3, input1 -> domain_name, sizeof(char) * (strlen(input1 -> domain_name) + 1));
    for(int i = 0; i < strlen(lower3); i++)
        lower3[i] = tolower(input1 -> domain_name[i]);
    memcpy(lower4, input2 -> domain_name, sizeof(char) * (strlen(input2 -> domain_name) + 1));
    for(int i = 0; i < strlen(lower4); i++)
        lower4[i] = tolower(input2 -> domain_name[i]);

    //printf("%s %s\n", lower1, input1 -> username);

    if(strcmp(lower1, lower2) < 0)
        return -1;
    if(strcmp(lower1, lower2) > 0)
        return 1;
    if(strcmp(lower1, lower2) == 0) {
        if(strcmp(lower3, lower4) > 0)
            return 1;
        if(strcmp(lower3, lower4) < 0)
            return -1;
    }

    return 0;
}

int compare_domain_name(const void *a, const void *b)
{
    struct email *input1 = (struct email *)a, *input2 = (struct email *)b;
    char lower1[200], lower2[200], lower3[200], lower4[200];
    //struct email lower1 = *input1, lower2 = *input2; wrong because struct email is declared using char *
    memcpy(lower1, input1 -> username, sizeof(char) * (strlen(input1 -> username) + 1));
    for(int i = 0; i < strlen(lower1); i++)
        lower1[i] = tolower(input1 -> username[i]);
    memcpy(lower2, input2 -> username, sizeof(char) * (strlen(input2 -> username) + 1));
    for(int i = 0; i < strlen(lower2); i++)
        lower2[i] = tolower(input2 -> username[i]);
    memcpy(lower3, input1 -> domain_name, sizeof(char) * (strlen(input1 -> domain_name) + 1));
    for(int i = 0; i < strlen(lower3); i++)
        lower3[i] = tolower(input1 -> domain_name[i]);
    memcpy(lower4, input2 -> domain_name, sizeof(char) * (strlen(input2 -> domain_name) + 1));
    for(int i = 0; i < strlen(lower4); i++)
        lower4[i] = tolower(input2 -> domain_name[i]);

    //printf("%s %s\n", lower1, input1 -> username);

    if(strcmp(lower3, lower4) < 0)
        return -1;
    if(strcmp(lower3, lower4) > 0)
        return 1;
    if(strcmp(lower3, lower4) == 0) {
        if(strcmp(lower1, lower2) > 0)
            return 1;
        if(strcmp(lower1, lower2) < 0)
            return -1;
    }

    return 0;
}


int main()
{
    //Prompt the user to input the number of cases and check for validity
    int cases;
    while(1) {
        printf("Please enter the quantity of email addresses the input will consist: ");

        char input_case[100];
        fgets(input_case, 100, stdin);
        if((cases = atoi(input_case)) == 0) //atoi will return 0 if the input is invalid
            printf("Please enter a number that consists only 0~9 and not just 0.\n");
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
        printf("The input is %s\n", input);

        //check inputted email address
        if(valid_input(input) == true) {
            //breakdown the input into username and domain name
            printf("Accepted input no.%d.\n", valid_count);

            /*
            account = strtok(email, "@");
            domain = strtok(NULL, "@");
            int account_len = strlen(account);
            int domain_len = strlen(domain);
            r->account = (char*) malloc (sizeof(char) * (account_len + 1));
            r->domain = (char*) malloc (sizeof(char) * (domain_len + 1));
            strncpy(r->account, account, account_len + 1);
            strncpy(r->domain, domain, domain_len + 1);
            */

            char *username = strtok(input, "@"), *domain_name = strtok(NULL, "\0");
            int username_len= strlen(username), domain_name_len = strlen(domain_name);

            data[valid_count - 1].username = (char *) malloc(sizeof(char) * (username_len + 1));
            data[valid_count - 1].domain_name = (char *) malloc(sizeof(char) * (domain_name_len + 1));

            strcpy(data[valid_count - 1].username, username);
            strcpy(data[valid_count - 1].domain_name, domain_name);

            printf("The valid input %d is %s@%s (%d input(s) remaining)\n\n", valid_count, data[valid_count - 1].username, data[valid_count - 1].domain_name, cases - count);
        } else {
            valid_count--;
            printf(" (%d input(s) remaining)\n\n", cases - count);
        }
    }
    printf("All inputs have been checked. There are %d valid input put of %d.\n", valid_count, cases);

    printf("Current accepted email addresses:\n");
    for(int i = 0; i < valid_count; i++)
        printf("%d %s@%s\n", i, data[i].username, data[i].domain_name);
    printf("\n\n");

    //print out the result sorted by username
    printf("Sort by username -> domain name\n");
    qsort(data, valid_count, sizeof(struct email), compare_username); //be aware of the sizeof struct, not data
    for(int i = 0; i < valid_count; i++)
        printf("%d %s@%s\n", i, data[i].username, data[i].domain_name);
    printf("\n");

    //print out the result sorted by domain name

    printf("Sort by domain name -> username\n");
    qsort(data, valid_count, sizeof(struct email), compare_domain_name);
    for(int i = 0; i < valid_count; i++)
        printf("%d %s@%s\n", i, data[i].username, data[i].domain_name);
    printf("\n");

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
        printf("Input invalid -> missing characters after/before @ in the email address.");
        return false; //nothing before @
    }
    if((test.domain_name = strtok(NULL, "\0")) == NULL) {
        printf("Input invalid -> missing characters after/before @ in the email address.");
        return false; //nothing behind @
    }

    //Part 2 (check for legal characters), Part 3

    int dot_present = false;
    for(int i = 0; i < strlen(test.username); i++) {
        if(isalnum(test.username[i]) == 0 && test.username[i] != '.' && test.username[i] != '_') { //isalnum return 0 for false
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
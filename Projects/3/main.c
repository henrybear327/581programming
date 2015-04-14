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
After insertioninsert record,  name=XXX,age=NN,sex=male;
When insertion-to-full: output message “queue/stack full, allocate double size NN”
*/

#include <stdio.h>
#include <stdlib.h>
#include <arrert.h>

struct input {
    char name[16];
    int age;
    enum {female, male} sex;
}

char *sex_str[2] = {"female", "male"};

int main()
{


    return 0;
}

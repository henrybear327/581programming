#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum {
    MALE, FEMALE
} Gender;

typedef struct {
    char name[16];
    int age;
    Gender gender;
} Record;

int cmp_by_name(const void* a, const void* b) {
    Record* ra = (Record*) a;
    Record* rb = (Record*) b;
    int flag = strcmp(ra->name, rb->name);
    if (flag != 0)
        return flag;

    if (ra->age != rb->age)
        return ra->age - rb->age;

    return ra->gender - rb->gender;
}

typedef struct {
    int capacity;
    int size;
    Record* storage;
} Vector;

Vector* new_vector() {
    Vector* v = (Vector*) malloc (sizeof(Vector));
    v->capacity = 1;
    v->size = 0;
    v->storage = (Record*) malloc (sizeof(Record) * (v->size));
    return v;
}

bool push_back(Vector* v, const Record* record) {
    if (v->size + 1 > v->capacity) {
        Record* temp = (Record*) malloc (sizeof(Record) * (v->size));
        if (temp == NULL)
            return false;
        memcpy(temp, v->storage, sizeof(Record) * (v->size));
        free(v->storage);

        v->capacity = (v->capacity) * 2;
        v->storage = (Record*) malloc (sizeof(Record) * (v->capacity));
        if (v->storage == NULL)
            return false;
        memcpy(v->storage, temp, sizeof(Record) * (v->size));
        free(temp);

        printf("(Capacity not enough. Updated to %d), ", v->capacity);
    }

    memcpy(v->storage + (v->size), record, sizeof(Record));
    (v->size)++;

    return true;
}

void trim(char** s) {
    int len = strlen(*s);

    for (int i = len - 1; (*s)[i] == ' ' && i >= 0; i--)
        (*s)[i] = '\0';

    for (; **s && **s == ' '; (*s)++);
}

bool parse_record(const char* input, Record* record) {
    char s[1024];
    strcpy(s, input);

    char* name = strtok(s, ",");
    char* age = strtok(NULL, ",");
    char* gender = strtok(NULL, ",");

    if (name == NULL || age == NULL || gender == NULL) {
        puts("Illegal Format.");
        return false;
    }

    // trim the string
    trim(&name);
    trim(&age);
    trim(&gender);

    int name_len = strlen(name);
    int age_len = strlen(age);
    int gender_len = strlen(gender);

    if (name_len == 0 || age_len == 0 || gender_len == 0) {
        puts("Illegal Format.");
        return false;
    }

    // name
    if (name_len >= 2 && name[0] == '\"' && name[name_len - 1] == '\"') {
        name[name_len - 1] = '\0';
        name++;
        name_len = name_len - 2;
    }
    if (name_len == 0 || name_len > 16) {
        puts("Illegal Name. Length: 1 ~ 16.");
        return false;
    }

    // age
    bool is_valid_age = true;
    for (int i = 0; i < age_len; i++) {
        if (!isdigit(age[i])) {
            is_valid_age = false;
            return false;
        }
    }
    if (!is_valid_age || age_len >= 4) {
        puts("Illegal Age.");
        return false;
    }

    // Gender
    Gender g;
    if (strcmp(gender, "MALE") == 0)
        g = MALE;
    else if (strcmp(gender, "FEMALE") == 0)
        g = FEMALE;
    else {
        puts("Illegal Gender. <MALE/FEMALE>.");
        return false;
    }

    strcpy(record->name, name);
    record->age = atoi(age);
    record->gender = g;

    return true;
}

int main() {
    Vector* v = new_vector();

    char input[1024];
    while (fgets(input, 1024, stdin) != NULL) {
        int len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }

        Record r;
        printf("%-20s : ", input);
        if (parse_record(input, &r) == true && push_back(v, &r)) {
            puts("Success.");
        }
        else {
            continue;
        }
    }

    printf("---------------------------\n");
    printf("Storage (Sort by name): \n");

    qsort(v->storage, v->size, sizeof(Record), cmp_by_name);

    for (int i = 0; i < v->size; i++) {
        printf("%d: %s, %d, ", i+1, v->storage[i].name, v->storage[i].age);
        if (v->storage[i].gender == MALE)
            printf("MALE");
        else
            printf("FEMALE");
        printf("\n");
    }

    free(v->storage);
    free(v);

    return 0;
}

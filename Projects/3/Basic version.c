#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//宣告方式就不說了

struct data {
    char name[20];
    int age;
    enum {female, male} sex;
};

//抱歉我直接重打，因為時間不夠了...
int main()
{
    char input[1000];
    int capacity = 1, index = 0;
    struct data *record = (struct data *)malloc(sizeof(struct data) * capacity); //

    while(fgets(input, 1000, stdin) != NULL) {
        if(capacity == index) { //空間不夠
            printf("queue/stack full, allocate double size %d\n", capacity * 2);
            struct data *temp = (struct data *) malloc(sizeof(struct data) * capacity * 2); //兩倍大

            if(temp == NULL) //檢查有沒有拿到空間
                printf("Malloc failed.\n");

            memcpy(temp, record, sizeof(struct data) * (index + 1)); //複製現有資料到新空間
            free(record); //釋放舊空間
            record = temp; //改一下指標位址
            capacity *= 2;
        }

        char *p_name, *p_age, *p_sex;
        p_name = strtok(input, ","); //切割字串
        p_age = strtok(NULL, ",");
        p_sex = strtok(NULL, "\n");

        //printf("%s %s %s\n", p_name, p_age, p_sex);

        if(p_name == NULL || p_age == NULL || p_sex == NULL) { //檢查有無三種資料
            printf("Missing input\n");
            continue;
        }

        //name

        int str_i = 0;
        char str[18];
        if(strlen(p_name) > 18) {
            printf("Name too long.\n");
            continue;
        }

        for(int i = 0; i < (int)strlen(p_name); i++) { //移除雙引號
            if(p_name[i] != '"') {
                str[str_i++] = p_name[i];
            }
        }
        str[str_i] = '\0';
        //printf("%s\n", str);

        strcpy((record + index) -> name, str); //複製到struct中

        //age

        (record + index) -> age = atoi(p_age); //把age複製到struct中(沒防呆)

        //sex

        (record + index) -> sex = male; //預設是男生
        for(int i = 0; i < (int)strlen(p_sex); i++) {
            if(p_sex[i] == 'f' || p_sex[i] == 'F') { //沒防呆，字串有f就當作是女生
                (record + index) -> sex = female;
                break;
            }
        }

        char *gender_s[2] = {"female", "male"};
        printf("record %d: name = %s, age = %d, sex = %d %s\n", index + 1, (record + index) -> name, (record + index) -> age, (record + index) -> sex, gender_s[(record + index) -> sex]);

        index++;
    }
}

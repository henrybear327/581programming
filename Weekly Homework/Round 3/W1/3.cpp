#include <cstdio>
#include <cstring>
#include <queue>

typedef struct {
    int rating;
    int leader;
    int leafCount;

    int selected;
    int unselected;
} DATA;

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int test_cases;
    while (scanf("%d", &test_cases) != EOF) {
        while (test_cases--) {
            int total_members;
            scanf("%d", &total_members);
            DATA input[total_members + 1];
            memset(input, 0, sizeof(input));

            scanf("%d", &input[1].rating);
            input[1].selected = input[1].rating;
            for (int i = 2; i <= total_members; i++) {
                scanf("%d %d", &input[i].leader, &input[i].rating);
                input[i].selected = input[i].rating;
                input[input[i].leader].leafCount++;

                printf("i %d %d,  %d %d %d %d %d\n", i, total_members, input[i].rating,
                       input[i].leader, input[i].leafCount, input[i].selected,
                       input[i].unselected);
            }
            printf("here I am\n");
            getchar();

            for (int i = 1; i <= total_members; i++) {
                printf("i %d,  %d %d %d %d %d", i, input[i].rating, input[i].leader,
                       input[i].leafCount, input[i].selected, input[i].unselected);
            }

            std::queue<int> trim_leaf;
            for (int i = 1; i <= total_members; i++) {
                if (input[i].leafCount == 0) {
                    input[input[i].leader].selected += input[i].unselected;
                    input[input[i].leader].unselected +=
                        MAX(input[i].selected, input[i].unselected);
                    input[input[i].leader].leafCount--;

                    if (input[input[i].leader].leafCount == 0 && input[i].leader != 1) {
                        trim_leaf.push(i);
                    }
                }
            }

            while (trim_leaf.size() != 0) {
                input[input[trim_leaf.front()].leader].selected +=
                    input[trim_leaf.front()].unselected;
                input[input[trim_leaf.front()].leader].unselected +=
                    MAX(input[trim_leaf.front()].selected,
                        input[trim_leaf.front()].unselected);
                input[input[trim_leaf.front()].leader].leafCount--;

                if (input[input[trim_leaf.front()].leader].leafCount == 0 &&
                    input[trim_leaf.front()].leader != 1) {
                    trim_leaf.push(trim_leaf.front());
                }
            }
            printf("%d\n", MAX(input[1].selected, input[1].unselected));
        }
    }

    return 0;
}
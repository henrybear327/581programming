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
            }
            getchar();

            std::queue<int> trim_leaf;

            /*
                        for (int i = 1; i <= total_members; i++) {
                            printf("i %d,  %d %d %d %d %d\n", i, input[i].leader,
               input[i].rating,
                                   input[i].leafCount, input[i].selected,
               input[i].unselected);
                        }
            */

            for (int i = 2; i <= total_members; i++) {
                if (input[i].leafCount == 0)
                    trim_leaf.push(i);
            }

            while (trim_leaf.empty() == 0) {
                int temp = trim_leaf.front();
                trim_leaf.pop();

                input[input[temp].leader].selected += input[temp].unselected;
                input[input[temp].leader].unselected +=
                    MAX(input[temp].selected, input[temp].unselected);

                input[input[temp].leader].leafCount--;
                if (input[input[temp].leader].leafCount == 0)
                    trim_leaf.push(input[temp].leader);

                // printf("temp %d\n", temp);
            }

            printf("%d\n", MAX(input[1].selected, input[1].unselected));
        }
    }

    return 0;
}
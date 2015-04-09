#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct compare {
    bool operator()(const int& l, const int& r) {
        return l > r;
    }
};

int main()
{
    //std::priority_queue<int> mypq; //or just use simple priority queue and multiply -1 to every ter

    int test_case;
    while(scanf("%d", &test_case) != EOF) {
        while(test_case--) {
            int N, M;
            scanf("%d %d", &N, &M);
            priority_queue<int,vector<int>, compare > mypq;
            for (int i = 0; i < M; i++)
                mypq.push(0);

            while(N--) {
                int job;
                scanf("%d", &job);
                int temp = mypq.top();
                mypq.pop();
                temp += job;
                mypq.push(temp);
            }

            int answer;
            while (!mypq.empty()) {
                answer = mypq.top();
                mypq.pop();
            }

            printf("%d\n", answer);
        }
    }

    /*int sum (0);

    for (int i=10; i>= 1; i--) {
        mypq.push(i);
        std::cout << "mypq.top() is now " << mypq.top() << '\n';
    }

    std::cout << "size: " << mypq.size() << '\n';

    while (!mypq.empty()) {
        sum += mypq.top();
        mypq.pop();
    }

    std::cout << "total: " << sum << '\n';

    std::cout << "size: " << mypq.size() << '\n';
    */

    return 0;
}
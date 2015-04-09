#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(const int& l, const int& r) {
        return l > r;
    }
};

int main()
{
    //std::priority_queue<int> mypq; //or just use simple priority queue and multiply -1 to every term
    priority_queue<int,vector<int>, compare > mypq;

    int sum (0);

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

    return 0;
}
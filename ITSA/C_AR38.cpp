#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        int cnt[N+1];
        cnt[0] = -1;
        for (int i = 1; i <= N; i++)
            cin >> cnt[i];

        vector<int> v;
        v.push_back(N);
        for (int i = N-1; i >= 1; i--) {
            v.insert(v.begin() + cnt[i], i);
        }
        
        for (size_t i = 0; i < v.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}

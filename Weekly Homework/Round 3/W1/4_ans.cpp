#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
    int x, y;
} Rope;

int cmp(const void *a, const void *b)
{
    Rope *ra = (Rope *)a;
    Rope *rb = (Rope *)b;
    return ra->x - rb->x;
}

int main()
{
    int N;
    Rope a[50000];
    cin >> N;
    while (N--) {
        int num;
        cin >> num;
        for (int i = 0; i < num; i++) {
            cin >> a[i].x >> a[i].y;
        }
        qsort(a, num, sizeof(Rope), cmp);
        int ans = (a[0].y - a[0].x);
        int max = a[0].y;
        // for(int i=0; i<num; i++){
        //    cout << a[i].x << " " << a[i].y << "\n";
        //}
        for (int i = 1; i < num; i++) {
            ans += (a[i].y - a[i].x);
            // cout << a[i].x << " " << temp << "\n";
            if (a[i].x <= max) {
                if (a[i].y < max)
                    ans -= (a[i].y - a[i].x);
                else {
                    ans -= (max - a[i].x);
                    max = a[i].y;
                }
                // cout << "check" << "\n";
            } else
                max = a[i].y;
        }
        cout << ans << "\n";
    }
    return 0;
}
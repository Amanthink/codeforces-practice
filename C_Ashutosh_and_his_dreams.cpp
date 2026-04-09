#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct Q {
    int t, x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    vector<Q> qs(q);
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].t;
        if (qs[i].t == 1) cin >> qs[i].x;
        else cin >> qs[i].x >> qs[i].y;
    }

    const int M = 300005;
    vector<int> f(M);
    iota(f.begin(), f.end(), 0);

    vector<int> res;

    for (int i = q - 1; i >= 0; --i) {
        if (qs[i].t == 1) {
            res.push_back(f[qs[i].x]);
        } else {
            int x = qs[i].x, y = qs[i].y;
            if (x < M) {
                int tg = x + y;
                if (tg >= 0 && tg < M) f[x] = f[tg];
                else f[x] = tg;
            }
        }
    }

    reverse(res.begin(), res.end());

    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << (i + 1 == res.size() ? "" : " ");

    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> cnt(n + 1, 0);
        for (int v : a) if (v >= 1 && v <= n) ++cnt[v];

        // prefix sums of counts
        vector<int> pref(n + 1, 0);
        for (int v = 1; v <= n; ++v) pref[v] = pref[v - 1] + cnt[v];

        auto range_count = [&](int L, int R)->int {
            if (L > R || L > n) return 0;
            if (R > n) R = n;
            return pref[R] - pref[L - 1];
        };

        int need = n - k;
        int answer = 1;

        // try g from n down to 1 to find the maximum g
        for (int g = n; g >= 1; --g) {
            int64 S = 0;
            for (int t = 1; 1LL * t * g <= n; ++t) {
                int L = t * g;
                int R = min(n, (t + 1) * g - 1);
                int c = range_count(L, R);
                if (c) {
                    S += 1LL * t * c;
                    if (S >= need) break; // early out
                }
            }
            if (S >= need) { answer = g; break; }
        }

        cout << answer << '\n';
    }
    return 0;
}

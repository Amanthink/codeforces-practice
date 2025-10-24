#include <bits/stdc++.h>
using namespace std;

int main() {


    int t; 
    cin >> t;
    while (t--) {
        int n; long long m;
        cin >> n >> m;

        vector<long long> S(n), T(n), diff(n);
        for (int i = 0; i < n; i++) cin >> S[i];
        for (int i = 0; i < n; i++) cin >> T[i];

        for (int i = 0; i < n; i++) 
            diff[i] = T[i] - S[i] + 1;

       
        sort(diff.begin(), diff.end());

        for (int i = 0; i < n && m > 0; i++) {
            long long reduce = min(m, diff[i] - 1); // 
            diff[i] -= reduce;
            m -= reduce;
        }

        long double ans = 0;
        for (int i = 0; i < n; i++) 
            ans += 1.0L / diff[i];

        ans /= n;

        cout << fixed << setprecision(6) << ans << "\n";
    }
}

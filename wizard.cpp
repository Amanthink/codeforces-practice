#include <bits/stdc++.h>
using namespace std;
const int MOD = 676767677;

bool check(const vector<int>& a, int startDir) {
    int n = a.size();
    vector<int> dir(n); 
    dir[0] = startDir;

    for (int i = 0; i < n - 1; ++i) {
        int d = a[i] - a[i + 1];
        if (d == 1) {
            if (dir[i] != 1) return false;
            dir[i + 1] = 1;
        } else if (d == -1) {
            if (dir[i] != 0) return false;
            dir[i + 1] = 0;
        } else if (d == 0) {
            dir[i + 1] = 1 - dir[i];
        } else return false; 
    }

    vector<int> prefL(n + 1, 0), suffR(n + 2, 0);
    for (int i = 1; i <= n; ++i) prefL[i] = prefL[i - 1] + (dir[i - 1] == 0);
    for (int i = n; i >= 1; --i) suffR[i] = suffR[i + 1] + (dir[i - 1] == 1);

    for (int i = 1; i <= n; ++i) {
        int seen = prefL[i] + suffR[i];
        if (seen != a[i - 1]) return false;
    }
    return true;
}

int solve_wizards(int n, vector<int>& a) {
    int ways = 0;
    if (check(a, 0)) ways++;
    if (check(a, 1)) ways++;
    return ways % MOD;
}

int main() {
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve_wizards(n, a) << "\n";
    }
}

#include <bits/stdc++.h>
using namespace std;
int minRemovalToBalance(const string &s) {
    int n = s.size();
    int totalA = 0, totalB = 0;
    for (char c : s) {
        if (c == 'a') ++totalA;
        else ++totalB;
    }
    if (totalA == totalB) return 0;
    if (totalA == 0 || totalB == 0) return -1;
    int maxRemain = 2 * min(totalA, totalB);
    for (int remLen = maxRemain; remLen >= 2; remLen -= 2) {
        int needA = remLen / 2;
        int needB = remLen / 2;
        int remA = totalA - needA;
        int remB = totalB - needB;
        if (remA < 0 || remB < 0) continue;

        int best = n + 1;
        int countA = 0, countB = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            if (s[right] == 'a') ++countA;
            else ++countB;

           
            while (countA > remA || countB > remB) {
                if (s[left] == 'a') --countA;
                else --countB;
                ++left;
            }
            
            if (countA == remA && countB == remB) {
                best = min(best, right - left + 1);
            }
        }
        if (best <= n) return best;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << minRemovalToBalance(s) << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

// floor divide for possibly negative numerator: floor(num / den)
int64 floor_div(int64 n, int64 d) {
    if (d <= 0) throw;
    if (n >= 0) return n / d;
    return - ( ( -n + d - 1 ) / d );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s; cin >> s;
        vector<int64> queries(q);
        for (int i = 0; i < q; ++i) cin >> queries[i];

      
        int64 d = 1;
        int64 add = 0; 
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'B') {
                d *= 2;
            } else {
                add -= d;
            }
        }

        int cntB = 0;
        for (char c : s) if (c == 'B') ++cntB;
        
        for (int qi = 0; qi < q; ++qi) {
            int64 a = queries[qi];
            if (a == 0) {
                cout << 0 << '\n';
                continue;
            }
            if (cntB == 0) {
                cout << a << '\n';
                continue;
            }

            int64 seconds = 0;
           
            const int64 THR = 1000000;
            while (a > THR) {
                int64 num = a + add;
                int64 na = floor_div(num, d);
                if (na >= a) {
                    break;
                }
                seconds += n;
                a = na;
                if (a == 0) break;
            }

            if (a > 0) {
               
                int idx = 0;
                while (a > 0) {
                    if (s[idx] == 'A') {
                        a -= 1;
                    } else {
                        a = a / 2;
                    }
                    ++seconds;
                    idx = (idx + 1);
                    if (idx == n) idx = 0;
                }
            }

            cout << seconds << '\n';
        }
    }
    return 0;
}

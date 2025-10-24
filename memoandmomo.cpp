#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; 
    while (t--) {
        long long n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;
        vector<pair<long long, long long>> corners = {{0,0},{0,n},{n,0},{n,n}};
        long long ans = 0;
        bool infinite = false;
        for (auto corner : corners) {
            long long k_dist = abs(rk - corner.first) + abs(ck - corner.second);  // Fixed: ck instead of cd
            long long d_dist = max(abs(rd - corner.first), abs(cd - corner.second));
            if (k_dist < d_dist) {
                ans = max(ans, d_dist - k_dist + 1);
            }
            if (k_dist == d_dist) {
                infinite = true;
            }
        }
        cout << (infinite ? -1 : ans) << '\n';
    }
}

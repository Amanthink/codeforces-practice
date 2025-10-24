#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // Positions of zeros and ones globally
        vector<int> pos0, pos1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) pos0.push_back(i);
            else pos1.push_back(i);
        }

        // Prefix sums to count zeros and ones quickly
        vector<int> prefix0(n + 1, 0), prefix1(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix0[i + 1] = prefix0[i] + (a[i] == 0 ? 1 : 0);
            prefix1[i + 1] = prefix1[i] + (a[i] == 1 ? 1 : 0);
        }

        auto count_in_range = [&](const vector<int>& prefix, int l, int r) -> int {
            return prefix[r + 1] - prefix[l];
        };

        auto cost_for_type = [&](const vector<int>& positions, int l, int r) -> ll {
            // Find lower and upper bounds for positions in range [l, r]
            int left_idx = (int)(std::lower_bound(positions.begin(), positions.end(), l) - positions.begin());
            int right_idx = (int)(std::upper_bound(positions.begin(), positions.end(), r) - positions.begin()) - 1;
            if (left_idx > right_idx) return 0;
            int length = right_idx - left_idx + 1;
            if (length % 3 != 0) return -1;

            ll cost = 0;
            // Sum minimal triple costs in this segment
            for (int i = left_idx; i + 2 <= right_idx; i += 3) {
                int d1 = positions[i + 1] - positions[i];
                int d2 = positions[i + 2] - positions[i + 1];
                cost += min(d1, d2);
            }
            return cost;
        };

        while (q--) {
            int l, r; cin >> l >> r;
            l--; r--; // zero-based indexing

            int c0 = count_in_range(prefix0, l, r);
            int c1 = count_in_range(prefix1, l, r);

            if (c0 % 3 != 0 || c1 % 3 != 0) {
                cout << -1 << "\n";
                continue;
            }

            ll cost0 = cost_for_type(pos0, l, r);
            ll cost1 = cost_for_type(pos1, l, r);

            if (cost0 == -1 || cost1 == -1) cout << -1 << "\n";
            else cout << cost0 + cost1 << "\n";
        }
    }

    return 0;
}

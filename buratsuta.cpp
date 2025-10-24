#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const vector<int>& positions, int l, int r) {
    auto leftIdx = (int)(lower_bound(positions.begin(), positions.end(), l) - positions.begin());
    auto rightIdx = (int)(upper_bound(positions.begin(), positions.end(), r) - positions.begin());
    return rightIdx - leftIdx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; i++) {
            positions[arr[i]].push_back(i + 1);  
        }

        while (q--) {
            int l, r; cin >> l >> r;
            int len = r - l + 1;
            int threshold = len / 3;

            set<int> candidates;
            vector<int> checkPos = {l, r, (l + r) / 2};
            for (int pos : checkPos) {
                if (pos <= r && pos >= l) {
                    candidates.insert(arr[pos - 1]);
                }
            }

            vector<int> res;
            for (int val : candidates) {
                int freq = countOccurrences(positions[val], l, r);
                if (freq > threshold) res.push_back(val);
            }

            if (res.empty()) {
                cout << -1 << "\n";
            } else {
                sort(res.begin(), res.end());
                for (int val : res) cout << val << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}

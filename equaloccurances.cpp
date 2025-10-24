#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;   
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int,int> freq;
        for (int x : a) freq[x]++;
        vector<int> sec;
        for (auto &p : freq) sec.push_back(p.second);

        int ans = 0;
        int max_freq = *max_element(sec.begin(), sec.end());
      
        for (int k = 1; k <= max_freq; ++k) {
            int cnt = 0;
            for (int f : sec) {
                if (f >= k) cnt++;
            }
            ans = max(ans, cnt * k);
        }
        cout << ans << endl;
    }
    return 0;
}

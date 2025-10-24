#include <bits/stdc++.h>
using namespace std;

int main() {
 

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        unordered_map<int,int> freq;
        for (auto x : a) freq[x]++;
       
        cout << alice << " " << bob << "\n";
    }
}

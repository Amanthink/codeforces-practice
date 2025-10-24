#include <bits/stdc++.h>
using namespace std;

int main(){
   
    int t;
    if (!(cin >> t)) return 0;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // Find position of the largest element n
        int po = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == n) {
                po = i;
                break;
            }
        }
        bool ok = true;
        // Check strictly increasing on left of pos
        for (int i = 0; i < po; i++) {
            if (a[i] >= a[i+1]) {
                ok = false;
                break;
            }
        }
        // Check strictly decreasing on right of pos
        for (int i = po; i < n-1 && ok; i++) {
            if (a[i] <= a[i+1]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

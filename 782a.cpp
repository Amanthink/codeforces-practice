#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  

    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }

    set<int> s;
    int ans = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (s.find(arr[i]) != s.end()) {
            s.erase(arr[i]); 
        } else {
            s.insert(arr[i]);
            ans = max(ans, (int)s.size());
        }
    }

    cout << ans << endl;  
    return 0;
}

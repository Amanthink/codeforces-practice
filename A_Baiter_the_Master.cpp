#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    int t = 0;
    for (int i = 0; i < n; ++i) 
    {
        cin >> b[i];
        t ^= b[i];
    }
    if (t == 0) 
    {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) 
    {
        if (b[i] == t) 
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
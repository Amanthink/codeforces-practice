#include <bits/stdc++.h>
using namespace std;
int n, t[200005];
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    int maxi=0;
    for (int i=2; i<=n; i+=2) maxi=max(maxi, t[i]-t[i-1]);
    cout << maxi << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
}

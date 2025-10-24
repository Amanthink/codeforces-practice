#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(const string &s, const string &target) {
    int j = 0;
    for (char c : s) {
        if (j < (int)target.size() && c == target[j])
            j++;
    }
    return j == (int)target.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << (isSubsequence(s, "ezpc") ? "YES\n" : "NO\n");
    }
}

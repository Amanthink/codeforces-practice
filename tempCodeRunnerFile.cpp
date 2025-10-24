#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s; 
        cin >> s;
        string p = "ezpc";

        for (char c : s)
        {
            if (!p.empty() && c == p.front())
                p.erase(p.begin());
        }

        cout << (p.empty() ? "YES\n" : "NO\n");
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int solve(long long z, const string &s)
{
    int n = (int)s.size();
    int i = 0;
    int seconds = 0;
    while (z > 0)
    {
        if (s[i] == 'A')
            z = z - 1;
        else 
            z = z / 2;
        seconds++;
        i = (i + 1) % n;
    }
    return seconds;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<long long> queries(q);
        for (int i = 0; i < q; i++)
            cin >> queries[i];

        for (int i = 0; i < q; i++)
        {
            cout << solve(queries[i], s) << "\n";
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
 
        int first = -1, last = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (first == -1) first = i;
                last = i;
            }
        }

        bool valid = true;
        if (first != -1) {
            for (int i = first; i <= last; ++i) {
                if (s[i] == '0') valid = false;
            }
        }

        if (!valid) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> p(n);
        int cur = 1;
        // Place values for stable ones
        for (int i = first; i <= last; ++i)
            p[i] = cur++;
        // Place other values
        for (int i = 0; i < n; ++i) 
            if (i < first || i > last)
                p[i] = cur++;
        // Output the permutation
        for (int i = 0; i < n; ++i)
            cout << p[i] << " ";
        cout << "\n";
    }
}

       

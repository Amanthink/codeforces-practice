#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for (char &c : s1) c = tolower(c);
    for (char &c : s2) c = tolower(c);

   if(s1==s2)cout<<"0";
   else if(s1<s2) cout<<"-1";
   else cout<<"1";
}

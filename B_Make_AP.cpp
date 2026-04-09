#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a , b , c;
        cin >> a >> b >> c;

        int d = 0;

        if(abs(c - a) % 2 == 0) {
            d = abs(c - a) / 2;

            if(d % b == 0||b%d==0) cout << "YES\n";
            else cout << "NO\n";
        }
        else cout << "NO\n";
    }

    return 0;
}
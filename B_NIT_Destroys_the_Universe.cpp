#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int segments = 0;

        for(int i = 0; i < n; i++){
            if(a[i] != 0 && (i == 0 || a[i-1] == 0)){
                segments++;
            }
        }

        if(segments == 0) cout << 0 << endl;
        else if(segments == 1) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}
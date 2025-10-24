#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long h, d;
        cin >> h >> d;
        
        long long curr= 0;
        long long ans = 0;
        long long moves = 0;
        
        while(curr < d){
            long long price = moves + 1;
            if(h > price){
                h -= price;
                curr++;
                moves++;
                ans++;
            } else {
                h++;
                moves = 0;  
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

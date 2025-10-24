#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if(!(cin >> t)) return 0;
    while(t--){
        int n, k; 
        cin >> n >> k;
        string s; 
        cin >> s;

        long long min_top = 1, max_top = 1;  
        long long min_bottom = n, max_bottom = n;  
        for(char c : s){
            if(c == '0'){
                ++min_top; ++max_top;
            }else if(c == '1'){
                --min_bottom; --max_bottom;
            }else{ 
                long long new_min_top = min_top;
                long long new_max_top = max_top + 1;
                long long new_min_bottom = min_bottom - 1;
                long long new_max_bottom = max_bottom;
                min_top = new_min_top; max_top = new_max_top;
                min_bottom = new_min_bottom; max_bottom = new_max_bottom;
            }
        }

        string ans;
        ans.reserve(n);
        for(int card = 1; card <= n; ++card){
            if(card < min_top || card > max_bottom) ans.push_back('-');
            else if(card >= max_top && card <= min_bottom) ans.push_back('+');
            else ans.push_back('?');
        }
        cout << ans << '\n';
    }
    return 0;
}

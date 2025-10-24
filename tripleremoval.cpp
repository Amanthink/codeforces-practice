#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        int n,q; cin >> n >> q;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) cin >> arr[i];
        vector<int> pos0, pos1;
        for(int i=1;i<=n;i++){
            if(arr[i]==0) pos0.push_back(i);
            else pos1.push_back(i);
        }

   
        int m0 = pos0.size(), m1 = pos1.size();
        vector<long long> cv0(max(0,m0-2)), cv1(max(0,m1-2));
        for(int i=0;i+2<m0;i++){
            int d1 = pos0[i+1] - pos0[i];
            int d2 = pos0[i+2] - pos0[i+1];
            cv0[i] = min(d1, d2);
        }
        for(int i=0;i+2<m1;i++){
            int d1 = pos1[i+1] - pos1[i];
            int d2 = pos1[i+2] - pos1[i+1];
            cv1[i] = min(d1, d2);
        }

        vector<long long> ps0[3], ps1[3];
        for(int r=0;r<3;r++){
            ps0[r].resize(cv0.size());
            ps1[r].resize(cv1.size());
            long long run0=0, run1=0;
            for(int i=0;i<(int)cv0.size();i++){
                if(i%3==r) run0 += cv0[i];
                ps0[r][i] = run0;
            }
            for(int i=0;i<(int)cv1.size();i++){
                if(i%3==r) run1 += cv1[i];
                ps1[r][i] = run1;
            }
        }

        auto sum3 = [&](const vector<long long> ps[3], int L, int R)->long long{
            if(L>R) return 0;
            int r = (L%3+3)%3;
            auto get = [&](int idx)->long long{
                if(idx<0) return 0;
                if(idx>=(int)ps[r].size()) return ps[r].empty()?0:ps[r].back();
                return ps[r][idx];
            };
            return get(R) - get(L-1);
        };

        while(q--){
            int l,r; cin >> l >> r;
            long long ans = 0;
            bool ok = true;
            {
                int L = int(lower_bound(pos0.begin(), pos0.end(), l) - pos0.begin());
                int R = int(upper_bound(pos0.begin(), pos0.end(), r) - pos0.begin()) - 1;
                int len = R - L + 1;
                if(len>0){
                    if(len%3!=0) ok = false;
                    else ans += sum3(ps0, L, R-2);
                }
            }

            {
                int L = int(lower_bound(pos1.begin(), pos1.end(), l) - pos1.begin());
                int R = int(upper_bound(pos1.begin(), pos1.end(), r) - pos1.begin()) - 1;
                int len = R - L + 1;
                if(len>0){
                    if(len%3!=0) ok = false;
                    else ans += sum3(ps1, L, R-2);
                }
            }

            if(!ok) cout << -1 << "\n";
            else    cout << ans << "\n";
        }
    }

    return 0;
}

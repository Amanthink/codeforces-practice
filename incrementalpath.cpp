#include <bits/stdc++.h>
using namespace std;

unordered_map<long long,long long> parentMap;

long long findNext(long long x){
    auto it = parentMap.find(x);
    if(it==parentMap.end()) return x;
    return parentMap[x] = findNext(it->second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        string s; cin >> s;

        vector<long long> init(m);
        parentMap.clear();
        for(int i=0;i<m;i++) cin >> init[i];

        sort(init.begin(),init.end());
        for(long long a:init) parentMap[a]=findNext(a+1);

        vector<long long> blacks = init;

        for(int i=0;i<n;i++){
            long long pos=1;
            for(int j=0;j<=i;j++){
                if(s[j]=='A') pos++;
                else pos=findNext(pos+1);
            }
            if(parentMap.find(pos)==parentMap.end()){
                parentMap[pos]=findNext(pos+1);
                blacks.push_back(pos);
            }
        }

        sort(blacks.begin(),blacks.end());
        blacks.erase(unique(blacks.begin(),blacks.end()),blacks.end());
        cout<<blacks.size()<<"\n";
        for(long long x:blacks) cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}

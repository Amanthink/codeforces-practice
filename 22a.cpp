#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n); 
       if(n==1){cout<<arr[0];return 0;}

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    set<int> s(arr.begin(), arr.end());
  
        auto it = s.begin();
        ++it;  
        cout << *it << "\n";
    
    return 0;
}

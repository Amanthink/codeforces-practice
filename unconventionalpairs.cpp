#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);  
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end()); 
        
        int ans = 0; 
        
      
        for(int i = 0; i < n; i += 2) { 
            int diff = arr[i + 1] - arr[i]; 
            ans = max(ans, diff);  
        }
        
        cout << ans << endl; 
    }
    return 0;  
}

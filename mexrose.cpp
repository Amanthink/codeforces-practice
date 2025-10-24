#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        set<int> present;
        int k_count = 0;
        
        for(int num : arr) {
            if(num >= 0 && num < k) {
                present.insert(num);
            } else if(num == k) {
                k_count++;
            }
        }
        
        int missing = k - present.size();
        
        if(k_count == 0) {
            cout << missing << endl;
        } else {
            cout << max(missing, k_count) << endl;
        }
    }
    return 0;
}

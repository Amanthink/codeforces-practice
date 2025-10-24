#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> arr(2*n);
    for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }
        
        arr[n] = n;
        
        
        for (int i = 1; i < n; i++) {
            arr[n + i] = i;
        }
    for(auto &x:arr)cout<<x<<" ";
    cout<<endl;
}

}
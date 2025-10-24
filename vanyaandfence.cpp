#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,h; cin>>n>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=n;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>h) count++;
    }
    cout<<ans+count;

}
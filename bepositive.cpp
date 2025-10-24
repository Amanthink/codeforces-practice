#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int c0=0,c1=0;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            if(temp==0)c0++;
            else if(temp==-1)c1++;
        }
        int ans=c0;
        int rem=c1%2;
        if(rem==0) cout<<ans<<endl;
        else cout<<ans+2*rem<<endl;
    }
}
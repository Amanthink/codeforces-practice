#include<iostream>
using namespace std;
int main(){
    int k,n,w;
    cin>>k>>n>>w;
    int amt_pay=(k*(w)*(w+1))/2;
    int ans=0;
    if(n>=amt_pay) cout<<"0";
    else cout<< amt_pay-n;
    return 0;
}
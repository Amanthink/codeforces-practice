#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
     unordered_map<long long,bool>mp;
    for(int i=1;i<=10000;i++)
    {
        long long k=i*i*i;
        mp[k]=true;
    }
    while (t--)
    {
    int target;
    cin>>target;
    for(int i=1;i<10000;i++)
    {
        long long k=i*i*i;
        if(mp[target-k]) 
        {
            cout<<"YES"<<endl;
        break;
    }
        if(k>target)
        {
            cout<<"NO"<<endl;
            break;
        }
    }
    }
    
}
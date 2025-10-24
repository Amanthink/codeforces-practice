#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
   int n,m;
   cin>>n>>m;
      int max=0;
     
   
       vector<int>arr(m,0);
      for(int i=0;i<m;i++)cin>>arr[i];
 
      int s=arr.size();
      int j=0;
      while(j<s-1 && (arr[j]<arr[j+1])){ j++; }
        int k=arr[j];
 
    
        if( m>1 && k>=arr[1] && j<s-1 ){cout<<1<<endl;}
         else cout<<n-(max-1)<<endl;
        }
 
}
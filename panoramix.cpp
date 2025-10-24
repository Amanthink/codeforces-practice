#include<iostream>

using namespace std;
int main(){
    int n,m;cin>>n>>m;
    bool isit=true;
    for(int i=n+1;i<=m;i++){
        for(int j=2;j<=i;j++){
            if(i%j==0&&j!=m) { isit=false;}
            else if(i%j!=0&&j==m) { isit=true;}
        }
    }
    if(isit==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
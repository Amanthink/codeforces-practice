#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int x=a,y=b;
        for(int i=a;i<=b;i++){
            x=a++;
            if(b++<=c)y=b;
            if(x+y>=c&&x+y<=d) cout<<x<<" "<<y<<" "<<
        }
    }
}
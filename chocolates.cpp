#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    if((int)s[0]>=97&&(int)s[0]<129) {
        s[0]=s[0]-32;
    }
    for(int i=1;i<s.size();i++){
       
        if((int)s[i]>=65&&(int)s[i]<92) {
            s[i]=s[i]+32;
        }
    }
    cout<<s;
}
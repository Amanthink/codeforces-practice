#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,q;
    cin >> n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> quer(q);
    for(int i=0;i<q;i++){
        cin>>quer[i];
    }
    for(int i=0;i<q;i++){
    if(find(arr.begin(), arr.end(), quer[i]) != arr.end())
        cout << "found" <<endl;
    else
        cout <<"not found"<<endl;

    }
    return 0;
}

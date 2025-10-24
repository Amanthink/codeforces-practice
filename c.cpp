#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> arr(t);
    int tests = t;
    int test = 0;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int ca = 0, cb = 0;
        for (char c : s) {
            if (c == 'a') ca++;
            else cb++;
        }
        
        if (ca== cb) {
            arr[test++] = 0;
            continue;
        }
        
        int target= ca -cb;
        
        int length = n + 1;  
        
        for (int i = 0; i < n; i++) {
            int ca = 0, cb = 0;
            
            for (int j = i; j < n; j++) {
                if (s[j] == 'a') {
                    ca++;
                } else {
                    cb++;
                }
                
                if (ca - cb == target) {
                    int leng = j - i + 1;
                    length = min(length, leng);
                }
            }
        }
        
        if (length == n) {
            arr[test++] = -1;
        } else {
            arr[test++] = length;
        }
    }
    
    for(int i = 0; i <tests; i++){
        cout << arr[i] << endl;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

int min_steps(long long x, long long y) {
  
    if (y > x) {
        return 2;
    }
    
   
    if (y > 0 && y < x && min(y, x - y) > 1) {
        return 3;
    }
    
    return -1;
}

int main() {

    
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        cout << min_steps(x, y) << "\n";
    }
    return 0;
}

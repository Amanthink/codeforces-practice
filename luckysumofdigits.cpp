#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = -1, y = -1;

    for (int j = 0; j * 7 <= n; j++) {
        int rem = n - j * 7;
        if (rem % 4 == 0) {
            x = rem / 4;
            y = j;
        }
    }

    if (x == -1) {
        cout << -1;
    } else {
    
        cout << string(x, '4') << string(y, '7');
    }

    return 0;
}
